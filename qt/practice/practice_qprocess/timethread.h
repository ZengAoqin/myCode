#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QThread>
#include <QTime>
#include <QDebug>


class TimeThread : public QThread
{
    Q_OBJECT
public:
    explicit TimeThread(QObject* parent = nullptr);

signals:
    void sendStrTime(QString);

protected:
    virtual void run();
};

#endif // TIMETHREAD_H
