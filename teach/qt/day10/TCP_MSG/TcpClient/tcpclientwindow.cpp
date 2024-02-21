#include "tcpclientwindow.h"
#include "ui_tcpclientwindow.h"

TcpClientWindow::TcpClientWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TcpClientWindow)
{
    ui->setupUi(this);
    //��ȡ����������Ϣ
    connect(&m_socket, &QTcpSocket::readyRead, this, &TcpClientWindow::read_msg);
}

TcpClientWindow::~TcpClientWindow()
{
    delete ui;
}

//���ӷ�����
void TcpClientWindow::on_btnConnect_clicked()
{
    //��ȡIP��ַ�Ͷ˿ں�
    QString IP = ui->lineIP->text();
    QString port = ui->linePort->text();
    //���ӷ�����
    m_socket.connectToHost(IP, port.toUShort());
}

//��������
void TcpClientWindow::on_btnSend_clicked()
{
    //׼������
    QString text = ui->textEdit->toPlainText();
    //���͸�������
    m_socket.write(text.toUtf8());
}

//���
void TcpClientWindow::on_btnClear_clicked()
{
    ui->textBrowser->clear();
}

void TcpClientWindow::read_msg()
{
    //ͨ���׽��ֶ�ȡ������������
    QString msg = m_socket.readAll();
    ui->textBrowser->append(msg);
}
