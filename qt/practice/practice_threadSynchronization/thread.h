#ifndef THREAD1_H
#define THREAD1_H
#include <QThread>


class Thread1 : public QThread
{
    Q_OBJECT
signals:
    void sendmsg(QString);
public:
    explicit Thread1(QObject* parent = nullptr);
    ~Thread1();
    virtual void run();
};

class Thread2 : public QThread
{
    Q_OBJECT
signals:

public:
    explicit Thread2(QObject* parent = nullptr);
    ~Thread2();
    virtual void run();
};

#endif // THREAD1_H
