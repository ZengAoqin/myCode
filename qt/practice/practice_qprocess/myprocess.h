#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QWidget>
#include <QProcess>
#include <QThread>
#include "mythread.h"
#include "timethread.h"


namespace Ui {
class MyProcess;
}

class MyProcess : public QWidget
{
    Q_OBJECT

public:
    explicit MyProcess(QWidget *parent = nullptr);
    ~MyProcess();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void showStart();
    void showFinish();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_recieveStrTime(QString strTime);

private:
    Ui::MyProcess *ui;
    QProcess m_process;
    MyThread* t1;
    MyThread* t2;
    TimeThread* t3;
};

#endif // MYPROCESS_H
