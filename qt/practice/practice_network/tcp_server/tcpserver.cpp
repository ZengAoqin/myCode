#include "tcpserver.h"
#include "ui_tcpserver.h"

TcpServer::TcpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);

    m_server = new QTcpServer;
    m_on = false;

    //绑定新连接进入的信号与客户端新连接槽函数
    connect(m_server, &QTcpServer::newConnection, this, &TcpServer::new_client);
}

TcpServer::~TcpServer()
{
    delete ui;
    delete m_server;
}

//启动服务器
void TcpServer::on_btnStart_clicked()
{

    //获取端口号
    QString port = ui->linePort->text();
    //监听客户端连接
    if(!m_on)
    {
        m_on = true;
        m_server->listen(QHostAddress::Any, port.toUShort());
        ui->btnStart->setText("关闭TCP服务器");
        ui->textBrowser->append("服务器已开启");
    }
    else
    {
        m_on = false;
        m_server->close();
        ui->btnStart->setText("启动TCP服务器");
        ui->textBrowser->append("服务器已关闭");
    }
}

//客户端新连接槽函数
void TcpServer::new_client()
{
    //获取与客户端连接套接字
    QTcpSocket* socket = m_server->nextPendingConnection();
    //向客户端发送数据
    socket->write("server connected");
    ui->textBrowser->append("用户(" + socket->peerAddress().toString().remove("::ffff:") + ")上线了");

    //关联读取信号获取客户端消息
    connect(socket, &QTcpSocket::readyRead, this, &TcpServer::read_data);
    //绑定用户下线
    connect(socket, &QTcpSocket::disconnected, this, &TcpServer::client_disconnected);
}

//读取客户端发送的消息槽函数
void TcpServer::read_data()
{
    //获取客户端套接字
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    //获取客户端IP
    QString IP = socket->peerAddress().toString();
    IP.remove("::ffff:");
    //读取消息
    QString msg = socket->readAll();

    //显示数据
    ui->textBrowser->append("IP:" + IP + " msg:" + msg);

    QString text = "IP:" + IP + " msg:" + msg;
    socket->write(text.toUtf8());
}

//用户下线槽函数
void TcpServer::client_disconnected()
{
    //获取客户端套接字
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());
    //获取客户端IP
    QString IP = socket->peerAddress().toString();
    IP.remove("::ffff:");
    ui->textBrowser->append("用户(" + IP + ")下线了");
}
