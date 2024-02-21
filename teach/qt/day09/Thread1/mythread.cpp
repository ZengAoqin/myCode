#include "mythread.h"

MyThread::MyThread(QObject* parent)
{
    Q_UNUSED(parent)
}

MyThread::~MyThread()
{

}

void MyThread::run()
{
    qDebug() << "MyThread===" << this->objectName() << "priority" << this->priority();
    int i = 0;
    for(;;)
    {
        for(i = 0; i < 3; ++i)
        {
            qDebug() << this->objectName() << "MyThread===helloworld";
            QThread::sleep(1);
        }
    }
    //qDebug() << this->objectName() << "left";
}
