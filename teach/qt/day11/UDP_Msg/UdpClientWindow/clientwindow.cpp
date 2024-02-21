#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    //关联信号readyRead与槽函数read_data
    connect(&m_scoket, &QUdpSocket::readyRead, this, &ClientWindow::read_data);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

//连接并发送
void ClientWindow::on_btnSend_clicked()
{
    //获取IP地址和端口号
    QString IP = ui->lineIP->text();
    QString Port = ui->linePort->text();
    QString Data = ui->textEdit->toPlainText();

    //将内容通过ui界面得到ip地址和端口发送出去
    m_scoket.writeDatagram(Data.toUtf8(), QHostAddress(IP), Port.toUShort());
}

void ClientWindow::read_data()
{
    //定义保存数据
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);
    QHostAddress host;  //ip地址
    quint16 port;       //端口号
    //读取数据
    m_scoket.readDatagram(buffer, size, &host, &port);
    //准备显示数据
    QString data = host.toString() + ":" + QString(buffer);
    ui->textBrowser->append(data);
}
