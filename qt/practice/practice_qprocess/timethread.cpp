#include "timethread.h"


TimeThread::TimeThread(QObject *parent)
{
    Q_UNUSED(parent);
}

void TimeThread::run()
{
    QString strTime;
    for(;;)
    {
        strTime = QTime::currentTime().toString("hh:mm:ss");
//        qDebug() << strTime;
        emit sendStrTime(strTime);
        sleep(1);
    }
}
