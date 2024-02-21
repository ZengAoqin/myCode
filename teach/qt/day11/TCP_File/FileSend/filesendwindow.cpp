#include "filesendwindow.h"
#include "ui_filesendwindow.h"

FileSendWindow::FileSendWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FileSendWindow)
{
    ui->setupUi(this);
    //绑定（当客户端连接服务器以后，客户端连接成功以后发送信号connected）客户端掉线 disconnected信号
    connect(&m_scoket, &QTcpSocket::connected, this, &FileSendWindow::send_fileInfo);
    //当套接字发送完毕以后，会发送bytesWritten(qint64 bytes)
    connect(&m_scoket, &QTcpSocket::bytesWritten, this, &FileSendWindow::send_fileText);
}

FileSendWindow::~FileSendWindow()
{
    delete ui;
}

//获取文件路径
void FileSendWindow::on_btnFile_clicked()
{
    //通过文件对话框选择路径
    QString filepath = QFileDialog::getOpenFileName(this);
    //将文件路径更新到界面
    ui->lineFile->setText(filepath);
}

//连接服务器
void FileSendWindow::on_btnConect_clicked()
{
    //获取IP地址和端口号
    QString IP = ui->lineIP->text();
    QString port = ui->lineProt->text();
    m_scoket.connectToHost(IP, port.toUShort());    //连接服务器
    qDebug() << "connect";

    //初始化数据
    m_fileSize = 0;
    m_sendSize = 0;
}

//发送文件信息
void FileSendWindow::send_fileInfo()
{
    //获取文件的名称和大小
    QFileInfo info(ui->lineFile->text());       //获取选中文件的信息
    m_fileName = info.fileName();               //获取文件名
    m_fileSize = info.size();                   //文件大小

    //定义存储空间将文件大小和文件名称放到一起
    QByteArray array;
    //把array和数据流绑定在一起
    QDataStream stream(&array, QIODevice::WriteOnly);
    //将文件大小和文件名称给数据流
    stream << m_fileSize << m_fileName;

    //设置进度条的最大值
    ui->progressBar->setMaximum(m_fileSize);

    //对文件进行打开操作
    m_file.setFileName(ui->lineFile->text());
    m_file.open(QIODevice::ReadOnly);   //设置打开

    //发送数据流给接收方
    m_scoket.write(array);
}

//发送文件内容
void FileSendWindow::send_fileText(qint64 bytes)
{
    qDebug() << bytes;
    //判断文件是否可以发送
    if(m_sendSize < m_fileSize)
    {
        //读取文件内容
        QByteArray array = m_file.read(1024 * 10);
        //发送数据
        m_scoket.write(array);
        m_sendSize += array.size();     //累计发送大小
        qDebug() << "send file:" << m_sendSize;
        //设置进度条的显示
        ui->progressBar->setValue(m_sendSize);
    }
    else if(m_sendSize == m_fileSize)
    {
        qDebug() << "send file over" << m_sendSize;
        m_file.close(); //文件关闭
    }
}
