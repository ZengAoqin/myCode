#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_btnSend_clicked()
{
    //获取IP地址和端口号
    QString IP = ui->lineIP->text();
    QString port = ui->lineProt->text();
    //获取发送内容
    QString data = ui->textEdit->toPlainText();
    //将数据发送出去
    m_socket.writeDatagram(data.toUtf8(), QHostAddress(IP), port.toUShort());
}
