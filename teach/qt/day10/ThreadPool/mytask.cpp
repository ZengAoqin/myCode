#include "mytask.h"

MyTask::MyTask(QString name): m_name(name) {}

void MyTask::run()
{
    qDebug() << "start " << m_name;
    QThread::sleep(5);
    qDebug() << "end " << m_name;
}
