#include "filesendwindow.h"
#include "ui_filesendwindow.h"

FileSendWindow::FileSendWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FileSendWindow)
{
    ui->setupUi(this);
    //�󶨣����ͻ������ӷ������Ժ󣬿ͻ������ӳɹ��Ժ����ź�connected���ͻ��˵��� disconnected�ź�
    connect(&m_scoket, &QTcpSocket::connected, this, &FileSendWindow::send_fileInfo);
    //���׽��ַ�������Ժ󣬻ᷢ��bytesWritten(qint64 bytes)
    connect(&m_scoket, &QTcpSocket::bytesWritten, this, &FileSendWindow::send_fileText);
}

FileSendWindow::~FileSendWindow()
{
    delete ui;
}

//��ȡ�ļ�·��
void FileSendWindow::on_btnFile_clicked()
{
    //ͨ���ļ��Ի���ѡ��·��
    QString filepath = QFileDialog::getOpenFileName(this);
    //���ļ�·�����µ�����
    ui->lineFile->setText(filepath);
}

//���ӷ�����
void FileSendWindow::on_btnConect_clicked()
{
    //��ȡIP��ַ�Ͷ˿ں�
    QString IP = ui->lineIP->text();
    QString port = ui->lineProt->text();
    m_scoket.connectToHost(IP, port.toUShort());    //���ӷ�����
    qDebug() << "connect";

    //��ʼ������
    m_fileSize = 0;
    m_sendSize = 0;
}

//�����ļ���Ϣ
void FileSendWindow::send_fileInfo()
{
    //��ȡ�ļ������ƺʹ�С
    QFileInfo info(ui->lineFile->text());       //��ȡѡ���ļ�����Ϣ
    m_fileName = info.fileName();               //��ȡ�ļ���
    m_fileSize = info.size();                   //�ļ���С

    //����洢�ռ佫�ļ���С���ļ����Ʒŵ�һ��
    QByteArray array;
    //��array������������һ��
    QDataStream stream(&array, QIODevice::WriteOnly);
    //���ļ���С���ļ����Ƹ�������
    stream << m_fileSize << m_fileName;

    //���ý����������ֵ
    ui->progressBar->setMaximum(m_fileSize);

    //���ļ����д򿪲���
    m_file.setFileName(ui->lineFile->text());
    m_file.open(QIODevice::ReadOnly);   //���ô�

    //���������������շ�
    m_scoket.write(array);
}

//�����ļ�����
void FileSendWindow::send_fileText(qint64 bytes)
{
    qDebug() << bytes;
    //�ж��ļ��Ƿ���Է���
    if(m_sendSize < m_fileSize)
    {
        //��ȡ�ļ�����
        QByteArray array = m_file.read(1024 * 10);
        //��������
        m_scoket.write(array);
        m_sendSize += array.size();     //�ۼƷ��ʹ�С
        qDebug() << "send file:" << m_sendSize;
        //���ý���������ʾ
        ui->progressBar->setValue(m_sendSize);
    }
    else if(m_sendSize == m_fileSize)
    {
        qDebug() << "send file over" << m_sendSize;
        m_file.close(); //�ļ��ر�
    }
}
