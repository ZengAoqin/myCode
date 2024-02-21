#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>
#include <QThread>
#include "mywork.h"

namespace Ui
{
class MainWindows;
}

class MainWindows : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindows(QWidget* parent = nullptr);
    ~MainWindows();

private slots:
    void on_btnStart_clicked();

    void recv_myWork(QString);

    void on_btnKill_clicked();

signals:
    void start_th();

private:
    Ui::MainWindows* ui;
    //ʵ�����̶߳���
    QThread* m_pThread;
    //ʵ����QObject������Ķ���
    MyWork* m_pWork;
};

#endif // MAINWINDOWS_H
