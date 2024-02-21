#include "tcpclient.h"
#include "ui_tcpclient.h"

TcpClient::TcpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);

    //监听服务器发送消息信号 执行读取信息槽函数
    connect(&m_socket, &QTcpSocket::readyRead, this, &TcpClient::read_msg);
}

TcpClient::~TcpClient()
{
    delete ui;
}

//连接服务器
void TcpClient::on_btnConnect_clicked()
{
    //获取IP和port
    QString IP = ui->lineEdit_IP->text();
    QString port = ui->lineEdit_port->text();

    //连接服务器
    m_socket.connectToHost(IP, port.toUShort());
}

//发送数据
void TcpClient::on_btnSend_clicked()
{
    QString text = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    //发送给服务器
    m_socket.write(text.toUtf8());
}

//清除
void TcpClient::on_btnClear_clicked()
{
    ui->textBrowser->clear();
}

//读取信息槽函数
void TcpClient::read_msg()
{
    //通过套接字读取数据
    QString msg = m_socket.readAll();

    ui->textBrowser->append(msg);
}
