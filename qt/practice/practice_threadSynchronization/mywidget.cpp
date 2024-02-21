#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    m_t1 = new Thread1;
    m_t2 = new Thread2;

    connect(m_t1, &Thread1::sendmsg, this, &MyWidget::showmsg);

    int i;
    //局部线程池
    QThreadPool* pool = new QThreadPool;
    for (i = 1; i <= 10; ++i)
    {
        //添加任务并调用
        pool->start(new MyTask("任务:" + QString::number(i)));
    }
}

MyWidget::~MyWidget()
{
    delete ui;
    delete m_t1;
    delete m_t2;
}

//添加msg槽函数
void MyWidget::showmsg(QString msg)
{
    ui->textBrowser->append(msg);
}

//开启线程
void MyWidget::on_pushButton_clicked()
{
    m_t1->start();
    m_t2->start();
}

//关闭线程
void MyWidget::on_pushButton_2_clicked()
{
    m_t1->terminate();
    m_t2->terminate();
}

//线程池添加任务
void MyWidget::on_pushButton_3_clicked()
{
    //创建任务
    MyTask* task = new MyTask(ui->lineEdit->text());
//    //创建全局线程池
//    QThreadPool* pool = QThreadPool::globalInstance();
//    //添加任务并调用
//    pool->start(task);

    QThreadPool::globalInstance()->start(task);
}
