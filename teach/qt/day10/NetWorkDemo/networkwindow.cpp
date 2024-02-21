#include "networkwindow.h"
#include "ui_networkwindow.h"

NetWorkWindow::NetWorkWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::NetWorkWindow)
{
    ui->setupUi(this);
}

NetWorkWindow::~NetWorkWindow()
{
    delete ui;
}

void NetWorkWindow::on_pushButton_clicked()
{
    qDebug() << QHostInfo::localHostName() << "" << QHostInfo::localDomainName();
    //��ȡ�������е�������ַ
    QList<QHostAddress> Address = QNetworkInterface::allAddresses();
    //addr����ͨ��ѭ����������ȡAddress�����ַ
    foreach(QHostAddress addr, Address)
    {
        ui->textBrowser->append(addr.toString());
    }
}
