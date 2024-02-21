#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTimer>

namespace Ui
{
class Timer;
}

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timer(QWidget* parent = nullptr);
    ~Timer();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void update_show();
private:
    Ui::Timer* ui;
    QTimer m_timer; //实例化定时器类对象
};

#endif // TIMER_H
