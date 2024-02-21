#include "mythread.h"

MyThread::MyThread(QObject* parent): QThread(parent) {}

MyThread::~MyThread() {}

void MyThread::run()
{
    QString strTime;
    for(;;)
    {
        //获取当前时间
        strTime = QTime::currentTime().toString("hh:mm:ss");
        qDebug() << strTime;
        //通过信号将数据更新到主线程
        emit sendStrTime(strTime);
        //延迟
        sleep(1);
    }
}
