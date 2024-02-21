#include "mythread1.h"
#include "ui_mythread1.h"

MyThread1::MyThread1(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MyThread1),
    m_th1(new MyThread), m_th2(new MyThread)
{
    ui->setupUi(this);
    m_th1->setObjectName(QString::fromLocal8Bit("�߳�һ")); //���߳�ȡ��

    m_th2->setObjectName(QString::fromLocal8Bit("�̶߳�")); //���߳�ȡ��
    //���start�����Ƿ��Ϳ�ʼ�ź�
    connect(m_th1, &MyThread::started, this, &MyThread1::showStart);
    connect(m_th2, &MyThread::finished, this, &MyThread1::showFinished);

}

void MyThread1::showStart()
{
    qDebug() << QString::fromLocal8Bit("�ҽ��ܵ����߳̿������ź�");
}

void MyThread1::showFinished()
{
    qDebug() << QString::fromLocal8Bit("�ҽ��ܵ����߳�Finished���ź�");
}

MyThread1::~MyThread1()
{
    delete ui;
    delete m_th1;
    delete m_th2;
}

void MyThread1::on_BtnStart_clicked()
{
    m_th1->start();
    //�����߳����ȼ���������֮�󣬲�������
    m_th1->setPriority(QThread::HighPriority);
    m_th2->start();
}

void MyThread1::on_BtnKill_clicked()
{
    m_th1->terminate();
    m_th2->terminate();
    qDebug() << QString::fromLocal8Bit("����ر��߳�");
}
