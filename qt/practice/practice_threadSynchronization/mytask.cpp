#include "mytask.h"
#include <QDebug>


MyTask::MyTask(QString name)
{
    m_name = name;
}

void MyTask::run()
{
    qDebug() << m_name << "start";
    QThread::sleep(3);
    qDebug() << m_name << "end";
}
