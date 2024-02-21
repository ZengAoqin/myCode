#include "photo.h"
#include "ui_photo.h"

Photo::Photo(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Photo),
    m_pTimer(new QTimer)
{
    ui->setupUi(this);
    m_currentIndex = 0;
    m_pTimer->setInterval(3000);
    connect(m_pTimer, &QTimer::timeout, this, &Photo::on_btnNext_clicked);
}

Photo::~Photo()
{
    delete ui;
}

void Photo::on_btnOpen_clicked()
{
    //�����ļ�������
    QString filter = "image(*bmp *.jpg *.png)";

    //��ȡͼƬ��·��
    m_dirpathList = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("ѡ��ͼƬ"), "./", filter);

    //��ȡͼƬ·��
    int i = 0;
    for(i = 0; i < m_dirpathList.size(); ++i)
    {
        qDebug() << m_dirpathList[i];
    }
    //��ʾͼƬ
    showPhoto(m_dirpathList[m_currentIndex]);
}

//��һ��
void Photo::on_btnLast_clicked()
{
    int size = m_dirpathList.size();
    //��ǰͼƬ����һ��
    m_currentIndex = (--m_currentIndex + size) % size;
    //��ʾͼƬ
    showPhoto(m_dirpathList[m_currentIndex]);
}

//��һ��
void Photo::on_btnNext_clicked()
{
    int size = m_dirpathList.size();
    //��ǰͼƬ����һ��ͼƬ
    m_currentIndex = (++m_currentIndex) % size;
    //��ʾͼƬ
    showPhoto(m_dirpathList[m_currentIndex]);
}

void Photo::showPhoto(QString filename)
{
    //ʵ���������
    QPixmap pix(filename);
    //��ȡlabel��size
    QSize size = ui->label->size();
    //��ͼƬ��size������label�Ĵ�С
    pix = pix.scaled(size);
    //��ʾͼƬ
    ui->label->setPixmap(pix);
    //������������ʾͼƬ·��
    ui->statusBar->showMessage(filename);
}

//�Զ�
void Photo::on_btnAuto_clicked()
{
    //������ʱ��
    m_pTimer->start();
}

//��ͣ
void Photo::on_btnStop_clicked()
{
    //ֹͣ��ʱ��
    m_pTimer->stop();
}
