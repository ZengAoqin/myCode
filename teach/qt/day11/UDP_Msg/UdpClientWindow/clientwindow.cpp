#include "clientwindow.h"
#include "ui_clientwindow.h"

ClientWindow::ClientWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    //�����ź�readyRead��ۺ���read_data
    connect(&m_scoket, &QUdpSocket::readyRead, this, &ClientWindow::read_data);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

//���Ӳ�����
void ClientWindow::on_btnSend_clicked()
{
    //��ȡIP��ַ�Ͷ˿ں�
    QString IP = ui->lineIP->text();
    QString Port = ui->linePort->text();
    QString Data = ui->textEdit->toPlainText();

    //������ͨ��ui����õ�ip��ַ�Ͷ˿ڷ��ͳ�ȥ
    m_scoket.writeDatagram(Data.toUtf8(), QHostAddress(IP), Port.toUShort());
}

void ClientWindow::read_data()
{
    //���屣������
    char buffer[1024] = {0};
    qint64 size = sizeof(buffer);
    QHostAddress host;  //ip��ַ
    quint16 port;       //�˿ں�
    //��ȡ����
    m_scoket.readDatagram(buffer, size, &host, &port);
    //׼����ʾ����
    QString data = host.toString() + ":" + QString(buffer);
    ui->textBrowser->append(data);
}
