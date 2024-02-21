#include "tcpserverwindow.h"
#include "ui_tcpserverwindow.h"

TcpServerWindow::TcpServerWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TcpServerWindow)
{
    ui->setupUi(this);
    //绑定新连接进入的信号与槽函数
    connect(&m_server, &QTcpServer::newConnection, this, &TcpServerWindow::new_client);
    m_falg = false;
}

TcpServerWindow::~TcpServerWindow()
{
    delete ui;
}

//启动服务器
void TcpServerWindow::on_btnStart_clicked()
{
    //获取端口号
    QString port = ui->linePort->text();
    if(!m_falg)
    {
        //监听客户端连接
        m_server.listen(QHostAddress::Any, port.toUShort());
        m_falg = true;
        ui->btnStart->setText(QString::fromLocal8Bit("关闭服务器"));
    }
    else
    {
        m_server.close();
        m_falg = false;
        ui->btnStart->setText(QString::fromLocal8Bit("启动服务器"));
    }

}

//获取新的连接客户端
void TcpServerWindow::new_client()
{
    //获取与客户端连接的套接字
    QTcpSocket* msocket = m_server.nextPendingConnection();
    //向客户端发送数据
    msocket->write("connect");
    //关联读取信号获取客户端的消息
    connect(msocket, &QTcpSocket::readyRead, this, &TcpServerWindow::read_data);
}

//读取客户端发送消息
void TcpServerWindow::read_data()
{
    //获取信号的发送者
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(sender());
    //读取发送者的消息
    QString msg = pSocket->readAll();
    //获取对端的ip地址
    QString IP = pSocket->peerAddress().toString();
    IP.remove("::ffff:");
    //显示对端的数据
    ui->textBrowser->append(IP + ":" + QString::fromLocal8Bit(msg.toLocal8Bit()));

}
