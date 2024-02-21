#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow)
{
    ui->setupUi(this);
    //�󶨷���readyRead�źźͶ�Ӧ�Ĳۺ���
    connect(&m_socket, &QUdpSocket::readyRead, this, &ServerWindow::read_data);
}

ServerWindow::~ServerWindow()
{
    delete ui;
}

//��ȡ����
void ServerWindow::read_data()
{
    //���屣������
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);    //����
    QHostAddress address;
    quint16 port;
    //readDatagram(char *data, qint64 maxSize, QHostAddress *address = nullptr, quint16 *port = nullptr)
    //��ȡ����
    m_socket.readDatagram(buffer, size, &address, &port);
    //��ui��������ʾ����
    QString data = address.toString() + ":" + QString(buffer);
    ui->textBrowser->append(data);

    //�ظ��ͻ���
    QByteArray array("hello:" + address.toString().toUtf8());
    m_socket.writeDatagram(array, address, port);
}

//����󶨰�ť
void ServerWindow::on_btnBind_clicked()
{
    //��ȡ�˿ں�
    QString port = ui->linePort->text();
    //��
    m_socket.bind(QHostAddress::Any, port.toUShort());
}
