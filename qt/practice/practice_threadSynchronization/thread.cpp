#include "thread.h"
#include "data.h"
#include <QDebug>


Thread1::Thread1(QObject *parent)
{
    Q_UNUSED(parent);
}

Thread1::~Thread1()
{

}

void Thread1::run()
{
    QString str;
    for(;;)
    {
        mutex.lock();
        sleep(1);
        qDebug() << "thread1:" << ++number;
        str = "thread1:" + QString::number(number);
        emit sendmsg(str);
        mutex.unlock();
    }
//    quit();
}


Thread2::Thread2(QObject *parent)
{
    Q_UNUSED(parent);
}

Thread2::~Thread2()
{

}

void Thread2::run()
{
    for(;;)
    {
        mutex.lock();
        sleep(1);
        qDebug() << "thread2:" << ++number;
        mutex.unlock();
    }
}
