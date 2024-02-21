#include "filerecvwindow.h"
#include "ui_filerecvwindow.h"

FileRecvWindow::FileRecvWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FileRecvWindow)
{
    ui->setupUi(this);
    //�����ͻ��ˣ����ͻ����Ƿ����ӳɹ�
    connect(&m_server, &QTcpServer::newConnection, this, &FileRecvWindow::new_client);
    //����������
    m_server.listen(QHostAddress::Any, 8000);
}

FileRecvWindow::~FileRecvWindow()
{
    delete ui;
}


void FileRecvWindow::new_client()
{
    //�ڰ󶨵Ĳۺ��������ȡ�ͻ��˵������׽���
    QTcpSocket* pSocket = m_server.nextPendingConnection();
    //���׽��ַ��͵����ݣ���ȡ���������
    connect(pSocket, &QTcpSocket::readyRead, this, &FileRecvWindow::read_data);

    //��ʼ������
    m_fileSize = 0;
    m_recvSize = 0;
}

//��������������
void FileRecvWindow::read_data()
{
    //��ȡ�׽��ֵķ�����
    QTcpSocket* pSocket = dynamic_cast<QTcpSocket*>(sender());
    //�ж��ļ���С����0����ȡ�ļ���Ϣ
    if(m_fileSize == 0) //��ȡ�ļ���Ϣ
    {
        //ͨ�����յ���������ȡ�ļ��Ĵ�С���ļ���
        QByteArray array = pSocket->readAll();  //��ȡ
        QDataStream stream(&array, QIODevice::ReadOnly);
        stream >> m_fileSize >> m_fileName; //��ȡ�ļ���С���ļ���

        //���ý�����
        qDebug() << m_fileSize << ":" << m_fileName;
        ui->progressBar->setMaximum(m_fileSize);
        //���ļ�
        m_file.setFileName(m_fileName);
        m_file.open(QIODevice::WriteOnly);
    }
    else if(m_recvSize < m_fileSize) //�����ļ�����
    {
        //��ȡ����
        QByteArray array = pSocket->readAll();
        m_file.write(array);
        m_recvSize += array.size();
        qDebug() << "recvFile: " << m_recvSize;
        //���ý�������ʾ
        ui->progressBar->setValue(m_recvSize);
    }

    if(m_recvSize == m_fileSize)
    {
        //�������
        m_file.close();
        qDebug() << "recv File Over";
        //�ر��׽���
        pSocket->disconnectFromHost();
    }
}
