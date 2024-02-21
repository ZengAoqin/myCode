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
    //��ȡIP��ַ�Ͷ˿ں�
    QString IP = ui->lineIP->text();
    QString port = ui->lineProt->text();
    //��ȡ��������
    QString data = ui->textEdit->toPlainText();
    //�����ݷ��ͳ�ȥ
    m_socket.writeDatagram(data.toUtf8(), QHostAddress(IP), port.toUShort());
}
