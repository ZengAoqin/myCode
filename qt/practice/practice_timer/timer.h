#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>


namespace Ui {
class Timer;
}

class Timer : public QWidget
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void update_show();

private:
    Ui::Timer *ui;
    QTimer m_timer;
    int m_time;
};

#endif // TIMER_H
