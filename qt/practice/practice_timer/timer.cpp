#include "timer.h"
#include "ui_timer.h"
#include <QDebug>
#include <QTime>
#include <QDate>
#include <QDateTime>


Timer::Timer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    //设置定时
    m_timer.setInterval(1000);
    m_time = 0;

    connect(&m_timer, &QTimer::timeout, this, &Timer::update_show);
}

Timer::~Timer()
{
    delete ui;
}

void Timer::update_show()
{
//    //获取时间
//    QString t = QTime::currentTime().toString("hh:mm:ss");
//    //日期
//    QString d = QDate::currentDate().toString("yyyy-MM-dd");

    m_time++;

    //获取时间和日期
    QString dt = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    //显示
    ui->lcdNumber->display(dt);
    ui->lcdNumber_2->display(QString::number(m_time));
}

//开启定时器
void Timer::on_pushButton_clicked()
{
    m_timer.start();
}

//停止定时器
void Timer::on_pushButton_2_clicked()
{
    m_timer.stop();
}
