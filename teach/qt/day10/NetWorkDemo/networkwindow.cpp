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
    //获取本地所有的主机地址
    QList<QHostAddress> Address = QNetworkInterface::allAddresses();
    //addr不断通过循环，遍历获取Address里面地址
    foreach(QHostAddress addr, Address)
    {
        ui->textBrowser->append(addr.toString());
    }
}
