#ifndef THREADTIME_H
#define THREADTIME_H

#include <QWidget>
#include "mythread.h"

namespace Ui
{
class ThreadTime;
}

class ThreadTime : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadTime(QWidget* parent = nullptr);
    ~ThreadTime();

private slots:
    void on_btnStart_clicked();

    void on_btnKill_clicked();

    void on_RecvTimeShow(QString strTime);

private:
    Ui::ThreadTime* ui;
    //实例化子线程
    MyThread* m_pThread;
};

#endif // THREADTIME_H
