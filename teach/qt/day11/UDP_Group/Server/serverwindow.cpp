#include "serverwindow.h"
#include "ui_serverwindow.h"

ServerWindow::ServerWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ServerWindow),
    m_pSocket(new QUdpSocket)
{
    ui->setupUi(this);
    //����readyRead�ź���ۺ���read_data
    connect(m_pSocket, &QUdpSocket::readyRead, this, &ServerWindow::read_data);
}

ServerWindow::~ServerWindow()
{
    delete ui;
    delete m_pSocket;
}

//����󶨰�ť
void ServerWindow::on_btnBind_clicked()
{
    //��ȡ�˿ں�
    QString port = ui->lineProt->text();
    //��
    m_pSocket->bind(QHostAddress::AnyIPv4, port.toUShort());
}

void ServerWindow::on_checkBox_clicked(bool checked)
{
    //��ȡ�鲥�ĵ�ַ
    QString IP = ui->lineGroup->text();
    //�ж��Ƿ�����鲥��ַ
    if(checked)
    {
        //�����鲥
        m_pSocket->joinMulticastGroup(QHostAddress(IP));
    }
    else
    {
        //�뿪�鲥
        m_pSocket->leaveMulticastGroup(QHostAddress(IP));
    }
}

//��ȡ����
void ServerWindow::read_data()
{
    //���屣������
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);       //����
    QHostAddress address;               //IP��ַ
    quint16 prot;                       //�˿ں�
    //��ȡ����
    m_pSocket->readDatagram(buffer, size, &address, &prot);
    ui->textBrowser->append(address.toString() + ":" + buffer);
}
