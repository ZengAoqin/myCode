#include "timer.h"
#include "ui_timer.h"
#include <QDebug>
#include <QTime> //ʱ��
#include <QDate> //����
#include <QDateTime>

Timer::Timer(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Timer)
{
    ui->setupUi(this);
    //�趨��ʱ����ʱ��
    m_timer.setInterval(1000);
    //�Ѷ�ʱ�����ź�timeout�Ͷ�Ӧ�Ĳۺ�������connect��
    connect(&m_timer, &QTimer::timeout, this, &Timer::update_show);
}

Timer::~Timer()
{
    delete ui;
}

//ʵ�ֲۺ���
void Timer::update_show()
{
    //��ȡʱ��
    QString t = QTime::currentTime().toString("hh:mm:ss");
    QString d = QDate::currentDate().toString("yyyy-MM-dd");
    QString dt = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    //�ڿؼ�����ʾʱ��
    ui->lcdTime->display(t);
    ui->lcdDate->display(d);
    ui->label->setText(dt);
}

//������ʱ���Ĳۺ���
void Timer::on_btnStart_clicked()
{
    m_timer.start();
}

//�رն�ʱ���Ĳۺ���
void Timer::on_btnStop_clicked()
{
    m_timer.stop();
}
