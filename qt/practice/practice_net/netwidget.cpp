#include "netwidget.h"
#include "ui_netwidget.h"

NetWidget::NetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NetWidget)
{
    ui->setupUi(this);
}

NetWidget::~NetWidget()
{
    delete ui;
}

//获取主机
void NetWidget::on_pushButton_clicked()
{
    //获取主机名
    QString hostname = QHostInfo::localHostName();
    qDebug() << "hostname:" << hostname;
    //获取域名
    QString domainname = QHostInfo::localDomainName();
    qDebug() << "domainname:" << domainname;

    //获取主机地址信息
    QList<QHostAddress> adList = QNetworkInterface::allAddresses();
    foreach(QHostAddress addr, adList)
    {
        ui->textBrowser->append(addr.toString());
    }

}
