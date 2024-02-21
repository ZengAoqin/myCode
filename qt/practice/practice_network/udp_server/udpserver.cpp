#include "udpserver.h"
#include "ui_udpserver.h"

UdpServer::UdpServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UdpServer)
{
    ui->setupUi(this);

    //关联readyRead信号与槽函数read_data
    connect(&m_socket, &QUdpSocket::readyRead, this, &UdpServer::read_data);
}

UdpServer::~UdpServer()
{
    delete ui;
}

//绑定
void UdpServer::on_pushButton_clicked()
{
    QString port = ui->lineEdit_port->text();
    bool flag = m_socket.bind(QHostAddress::AnyIPv4, port.toUShort());
    if(flag == true)
    {
        qDebug() << "绑定成功";
    }
    else
    {
        qDebug() << "绑定失败";
    }
}

//读取数据槽函数
void UdpServer::read_data()
{
    //定义保存数据
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);       //长度
    QHostAddress address;               //客户端IP地址
    quint16 port;                       //端口号

    m_socket.readDatagram(buffer, size, &address, &port);
    ui->textBrowser->append(address.toString().remove("::ffff:") + ":" + buffer);
    qDebug() << "port:" << port;
}

void UdpServer::on_checkBox_clicked(bool checked)
{
    //获取组播的地址
    QString IP = ui->lineEdit_group->text();
    //判断是否加入组播地址
    if(checked)
    {
        //加入组播
        m_socket.joinMulticastGroup(QHostAddress(IP));
    }
    else
    {
        //离开组播
        m_socket.leaveMulticastGroup(QHostAddress(IP));
    }
}
