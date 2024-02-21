#include "filerecvwindow.h"
#include "ui_filerecvwindow.h"

FileRecvWindow::FileRecvWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FileRecvWindow)
{
    ui->setupUi(this);
    //关联客户端，看客户端是否连接成功
    connect(&m_server, &QTcpServer::newConnection, this, &FileRecvWindow::new_client);
    //启动服务器
    m_server.listen(QHostAddress::Any, 8000);
}

FileRecvWindow::~FileRecvWindow()
{
    delete ui;
}


void FileRecvWindow::new_client()
{
    //在绑定的槽函数里面获取客户端的连接套接字
    QTcpSocket* pSocket = m_server.nextPendingConnection();
    //绑定套接字发送的内容，读取里面的数据
    connect(pSocket, &QTcpSocket::readyRead, this, &FileRecvWindow::read_data);

    //初始化数据
    m_fileSize = 0;
    m_recvSize = 0;
}

//服务器接收数据
void FileRecvWindow::read_data()
{
    //获取套接字的发送者
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(sender());
    //判断文件大小等于0，读取文件信息
    if(m_fileSize == 0) //读取文件信息
    {
        //通过接收的数据流获取文件的大小和文件名
        QByteArray array = pSocket->readAll();  //读取
        QDataStream stream(&array, QIODevice::ReadOnly);
        stream >> m_fileSize >> m_fileName; //获取文件大小和文件名

        //设置进度条
        qDebug() << m_fileSize << ":" << m_fileName;
        ui->progressBar->setMaximum(m_fileSize);
        //打开文件
        m_file.setFileName(m_fileName);
        m_file.open(QIODevice::WriteOnly);
    }
    else if(m_recvSize < m_fileSize) //接收文件内容
    {
        //读取内容
        QByteArray array = pSocket->readAll();
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
        pSocket->disconnectFromHost();
    }
}
