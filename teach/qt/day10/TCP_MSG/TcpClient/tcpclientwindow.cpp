#include "tcpclientwindow.h"
#include "ui_tcpclientwindow.h"

TcpClientWindow::TcpClientWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TcpClientWindow)
{
    ui->setupUi(this);
    //读取服务器的消息
    connect(&m_socket, &QTcpSocket::readyRead, this, &TcpClientWindow::read_msg);
}

TcpClientWindow::~TcpClientWindow()
{
    delete ui;
}

//连接服务器
void TcpClientWindow::on_btnConnect_clicked()
{
    //获取IP地址和端口号
    QString IP = ui->lineIP->text();
    QString port = ui->linePort->text();
    //连接服务器
    m_socket.connectToHost(IP, port.toUShort());
}

//发送数据
void TcpClientWindow::on_btnSend_clicked()
{
    //准备数据
    QString text = ui->textEdit->toPlainText();
    //发送给服务器
    m_socket.write(text.toUtf8());
}

//清除
void TcpClientWindow::on_btnClear_clicked()
{
    ui->textBrowser->clear();
}

void TcpClientWindow::read_msg()
{
    //通过套接字读取服务器的数据
    QString msg = m_socket.readAll();
    ui->textBrowser->append(msg);
}
