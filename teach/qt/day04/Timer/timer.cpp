#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
}

Timer::~Timer()
{
    delete ui;
}
