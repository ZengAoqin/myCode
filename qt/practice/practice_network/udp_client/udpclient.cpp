#include "udpclient.h"
#include "ui_udpclient.h"

UdpClient::UdpClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpClient)
{
    ui->setupUi(this);
}

UdpClient::~UdpClient()
{
    delete ui;
}

void UdpClient::on_pushButton_clicked()
{
    //获取IP地址和端口号
    QString IP = ui->lineEdit_IP->text();
    QString port = ui->lineEdit_port->text();
    //获取发送内容
    QString data = ui->textEdit->toPlainText();
    qDebug() << data;

    //将数据发送出去
    m_socket.writeDatagram(data.toUtf8(), QHostAddress(IP), port.toUShort());
}
