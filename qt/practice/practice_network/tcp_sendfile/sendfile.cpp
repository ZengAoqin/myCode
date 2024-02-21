#include "sendfile.h"
#include "ui_sendfile.h"

SendFile::SendFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendFile)
{
    ui->setupUi(this);

    //绑定连接信号
    connect(&m_socket, &QTcpSocket::connected, this, &SendFile::send_fileInfo);
    //当套接字发送完毕以后，会发送bytesWritten(qint64 bytes)
    connect(&m_socket, &QTcpSocket::bytesWritten, this, &SendFile::send_fileText);
}

SendFile::~SendFile()
{
    delete ui;
}

//获取文件路径
void SendFile::on_btnChoose_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this);
    ui->lineEdit_addr->setText(filePath);
}

//连接服务器
void SendFile::on_btnConnect_clicked()
{
    QString IP = ui->lineEdit_IP->text();
    QString port = ui->lineEdit_port->text();

    m_socket.connectToHost(IP, port.toUShort());
    qDebug() << "connect";

    //数据初始化
    m_fileSize = 0;
    m_sendSize = 0;
}

//发送文件信息
void SendFile::send_fileInfo()
{
    QFileInfo info(ui->lineEdit_addr->text());
    m_fileName = info.fileName();
    m_fileSize = info.size();

    qDebug() << "m_fileName" << m_fileName;

    //定义存储空间
    QByteArray array;
    //绑定array和流
    QDataStream stream(&array, QIODevice::WriteOnly);
    //将文件大小和文件名称给数据流
    stream << m_fileSize << m_fileName;

    //设置进度条大小
    ui->progressBar->setMaximum(static_cast<int>(m_fileSize));

    m_socket.write(array);
}

//发送文件内容
void SendFile::send_fileText(qint64 bytes)
{
    qDebug() << bytes;

    //打开文件
    m_file.setFileName(ui->lineEdit_addr->text());
    m_file.open(QIODevice::ReadOnly);

    //判断文件是否可以发送
    if(m_sendSize < m_fileSize)
    {
        //读取文件内容
        QByteArray array = m_file.read(1024 * 10);
        //发送数据
        m_socket.write(array);
        m_sendSize += array.size();     //累计发送大小
        qDebug() << "send file:" << m_sendSize;
        //设置进度条的显示
        ui->progressBar->setValue(static_cast<int>(m_sendSize));
    }
    else if(m_sendSize == m_fileSize)
    {
        qDebug() << "send file over" << m_sendSize;
        m_file.close(); //文件关闭
    }
}
