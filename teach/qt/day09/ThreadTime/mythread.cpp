#include "mythread.h"

MyThread::MyThread(QObject* parent): QThread(parent) {}

MyThread::~MyThread() {}

void MyThread::run()
{
    QString strTime;
    for(;;)
    {
        //��ȡ��ǰʱ��
        strTime = QTime::currentTime().toString("hh:mm:ss");
        qDebug() << strTime;
        //ͨ���źŽ����ݸ��µ����߳�
        emit sendStrTime(strTime);
        //�ӳ�
        sleep(1);
    }
}
