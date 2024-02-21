#include "tcpserverwindow.h"
#include "ui_tcpserverwindow.h"

TcpServerWindow::TcpServerWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TcpServerWindow)
{
    ui->setupUi(this);
    //�������ӽ�����ź���ۺ���
    connect(&m_server, &QTcpServer::newConnection, this, &TcpServerWindow::new_client);
    m_falg = false;
}

TcpServerWindow::~TcpServerWindow()
{
    delete ui;
}

//����������
void TcpServerWindow::on_btnStart_clicked()
{
    //��ȡ�˿ں�
    QString port = ui->linePort->text();
    if(!m_falg)
    {
        //�����ͻ�������
        m_server.listen(QHostAddress::Any, port.toUShort());
        m_falg = true;
        ui->btnStart->setText(QString::fromLocal8Bit("�رշ�����"));
    }
    else
    {
        m_server.close();
        m_falg = false;
        ui->btnStart->setText(QString::fromLocal8Bit("����������"));
    }

}

//��ȡ�µ����ӿͻ���
void TcpServerWindow::new_client()
{
    //��ȡ��ͻ������ӵ��׽���
    QTcpSocket* msocket = m_server.nextPendingConnection();
    //��ͻ��˷�������
    msocket->write("connect");
    //������ȡ�źŻ�ȡ�ͻ��˵���Ϣ
    connect(msocket, &QTcpSocket::readyRead, this, &TcpServerWindow::read_data);
}

//��ȡ�ͻ��˷�����Ϣ
void TcpServerWindow::read_data()
{
    //��ȡ�źŵķ�����
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(sender());
    //��ȡ�����ߵ���Ϣ
    QString msg = pSocket->readAll();
    //��ȡ�Զ˵�ip��ַ
    QString IP = pSocket->peerAddress().toString();
    IP.remove("::ffff:");
    //��ʾ�Զ˵�����
    ui->textBrowser->append(IP + ":" + QString::fromLocal8Bit(msg.toLocal8Bit()));

}
