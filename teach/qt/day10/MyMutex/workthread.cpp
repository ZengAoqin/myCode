#include "workthread.h"

//构造函数
WorkThread1::WorkThread1(QObject* parent): QThread(parent) {}

//析构函数
WorkThread1::~WorkThread1() {}

//重写run函数
void WorkThread1::run()
{
    QString str;
    for(;;)
    {
        mutex.lock();               //上锁
        QThread::sleep(1);          //延迟1秒
        qDebug() << "WorkThread1" << ++number;
        str = "WorkThread1,number:" + QString::number(number);
        emit sendmsg(str);
        mutex.unlock();             //解锁
    }
}

WorkThread2::WorkThread2(QObject* parent): QThread(parent) {}

WorkThread2::~WorkThread2() {}

void WorkThread2::run()
{
    for(;;)
    {
        mutex.lock();               //上锁
        QThread::sleep(1);          //延迟1秒
        qDebug() << "WorkThread2" << ++number;
        mutex.unlock();             //解锁
    }
}

