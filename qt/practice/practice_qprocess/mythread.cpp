#include "mythread.h"


MyThread::MyThread(QObject *parent)
{
    Q_UNUSED(parent);
}

MyThread::~MyThread()
{

}

void MyThread::run()
{
    qDebug() << "mythread:" << this->objectName();
    qDebug() << "priority:" << this->priority();
    for (int i = 0; i < 3; ++i)
    {
        qDebug() << this->objectName() << "helloworld";
        sleep(1);
    }
}
