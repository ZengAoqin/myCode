#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow),
    m_pSocket(new QUdpSocket)
{
    ui->setupUi(this);
    //关联readyRead信号与槽函数read_data
    connect(m_pSocket, &QUdpSocket::readyRead, this, &ServerWindow::read_data);
}

ServerWindow::~ServerWindow()
{
    delete ui;
    delete m_pSocket;
}

//点击绑定按钮
void ServerWindow::on_btnBind_clicked()
{
    //获取端口号
    QString port = ui->lineProt->text();
    //绑定
    m_pSocket->bind(QHostAddress::AnyIPv4, port.toUShort());
}

void ServerWindow::on_checkBox_clicked(bool checked)
{
    //获取组播的地址
    QString IP = ui->lineGroup->text();
    //判断是否加入组播地址
    if(checked)
    {
        //加入组播
        m_pSocket->joinMulticastGroup(QHostAddress(IP));
    }
    else
    {
        //离开组播
        m_pSocket->leaveMulticastGroup(QHostAddress(IP));
    }
}

//读取数据
void ServerWindow::read_data()
{
    //定义保存数据
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);       //长度
    QHostAddress address;               //IP地址
    quint16 prot;                       //端口号
    //读取数据
    m_pSocket->readDatagram(buffer, size, &address, &prot);
    ui->textBrowser->append(address.toString() + ":" + buffer);
}
