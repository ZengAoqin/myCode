#ifndef MyTask_H
#define MYTASK_H

#include <QRunnable>
#include <QString>
#include <QThread>

class MyTask : public QRunnable
{
public:
    explicit MyTask(QString name);
    virtual void run();

private:
    QString m_name;
};

#endif // MyTask_H
