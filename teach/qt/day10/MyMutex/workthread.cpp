#include "workthread.h"

//���캯��
WorkThread1::WorkThread1(QObject* parent): QThread(parent) {}

//��������
WorkThread1::~WorkThread1() {}

//��дrun����
void WorkThread1::run()
{
    QString str;
    for(;;)
    {
        mutex.lock();               //����
        QThread::sleep(1);          //�ӳ�1��
        qDebug() << "WorkThread1" << ++number;
        str = "WorkThread1,number:" + QString::number(number);
        emit sendmsg(str);
        mutex.unlock();             //����
    }
}

WorkThread2::WorkThread2(QObject* parent): QThread(parent) {}

WorkThread2::~WorkThread2() {}

void WorkThread2::run()
{
    for(;;)
    {
        mutex.lock();               //����
        QThread::sleep(1);          //�ӳ�1��
        qDebug() << "WorkThread2" << ++number;
        mutex.unlock();             //����
    }
}

