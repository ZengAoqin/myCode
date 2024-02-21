#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    //绑定发送readyRead信号和对应的槽函数
    connect(&m_socket, &QUdpSocket::readyRead, this, &ServerWindow::read_data);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

//读取数据
void ServerWindow::read_data()
{
    //定义保存数据
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);    //长度
    QHostAddress address;
    quint16 port;
    //readDatagram(char *data, qint64 maxSize, QHostAddress *address = nullptr, quint16 *port = nullptr)
    //读取数据
    m_socket.readDatagram(buffer, size, &address, &port);
    //在ui界面上显示数据
    QString data = address.toString() + ":" + QString(buffer);
    ui->textBrowser->append(data);

    //回复客户端
    QByteArray array("hello:" + address.toString().toUtf8());
    m_socket.writeDatagram(array, address, port);
}

//点击绑定按钮
void ServerWindow::on_btnBind_clicked()
{
    //获取端口号
    QString port = ui->linePort->text();
    //绑定
    m_socket.bind(QHostAddress::Any, port.toUShort());
}
