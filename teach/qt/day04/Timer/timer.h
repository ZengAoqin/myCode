#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>

namespace Ui {
class Timer;
}

class Timer : public QMainWindow
{
    Q_OBJECT

public:
    explicit Timer(QWidget *parent = nullptr);
    ~Timer();

private:
    Ui::Timer *ui;
};

#endif // TIMER_H
