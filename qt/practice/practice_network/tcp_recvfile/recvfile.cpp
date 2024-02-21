#include "recvfile.h"
#include "ui_recvfile.h"

RecvFile::RecvFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecvFile)
{
    ui->setupUi(this);

    //新连接
    connect(&m_server, &QTcpServer::newConnection, this, &RecvFile::new_client);

    //启动服务器
    m_server.listen(QHostAddress::Any, 8888);
}

RecvFile::~RecvFile()
{
    delete ui;
}

//新连接槽函数
void RecvFile::new_client()
{
    //获取套接字
    QTcpSocket* socket = m_server.nextPendingConnection();
    //绑定套接字发送数据
    connect(socket, &QTcpSocket::readyRead, this, &RecvFile::read_data);

    //数据初始化
    m_fileSize = 0;
    m_recvSize = 0;
}

//接收数据槽函数
void RecvFile::read_data()
{
    //获取发送者
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());

    //判断文件大小等于0，读取文件信息
    if(m_fileSize == 0) //读取文件信息
    {
        //通过接收的数据流获取文件的大小和文件名
        QByteArray array = socket->readAll();  //读取
        QDataStream stream(&array, QIODevice::ReadOnly);
        stream >> m_fileSize >> m_fileName; //获取文件大小和文件名

        //设置进度条
        qDebug() << "m_fileName:" << m_fileName << "m_fileSize:" << m_fileSize;
        ui->progressBar->setMaximum(m_fileSize);
        //打开文件
        m_file.setFileName(m_fileName);
        m_file.open(QIODevice::WriteOnly);
    }
    else if(m_recvSize < m_fileSize) //接收文件内容
    {
        //读取内容
        QByteArray array = socket->readAll();
        m_file.write(array);
        m_recvSize += array.size();
        qDebug() << "recvFile: " << m_recvSize;
        //设置进度条显示
        ui->progressBar->setValue(m_recvSize);
    }

    if(m_recvSize == m_fileSize)
    {
        //接收完成
        m_file.close();
        qDebug() << "recv File Over";
        //关闭套接字
        socket->disconnectFromHost();
    }
}
