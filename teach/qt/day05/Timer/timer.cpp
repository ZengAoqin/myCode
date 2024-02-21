#include "timer.h"
#include "ui_timer.h"
#include <QDebug>
#include <QTime> //时间
#include <QDate> //日期
#include <QDateTime>

Timer::Timer(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    //设定定时器的时间
    m_timer.setInterval(1000);
    //把定时器的信号timeout和对应的槽函数进行connect绑定
    connect(&m_timer, &QTimer::timeout, this, &Timer::update_show);
}

Timer::~Timer()
{
    delete ui;
}

//实现槽函数
void Timer::update_show()
{
    //获取时间
    QString t = QTime::currentTime().toString("hh:mm:ss");
    QString d = QDate::currentDate().toString("yyyy-MM-dd");
    QString dt = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    //在控件上显示时间
    ui->lcdTime->display(t);
    ui->lcdDate->display(d);
    ui->label->setText(dt);
}

//开启定时器的槽函数
void Timer::on_btnStart_clicked()
{
    m_timer.start();
}

//关闭定时器的槽函数
void Timer::on_btnStop_clicked()
{
    m_timer.stop();
}
