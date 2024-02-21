#include "treadpoolwindow.h"
#include "ui_treadpoolwindow.h"

TreadPoolWindow::TreadPoolWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TreadPoolWindow)
{
    ui->setupUi(this);
    int number = 0, i = 0;
    //局部线程池
    QThreadPool* pool = new QThreadPool;
    for(i = 0; i < 10; ++i)
    {
        //添加任务并调用
        pool->start(new MyTask(QString::fromLocal8Bit("任务") + QString::number(number)));
        number++;
    }
}

TreadPoolWindow::~TreadPoolWindow()
{
    delete ui;
}

void TreadPoolWindow::on_pushButton_clicked()
{
    //创建任务数据
    MyTask* pTask = new MyTask(ui->lineEdit->text());
    //获取全局线程池
    QThreadPool* pool = QThreadPool::globalInstance();
    //用线程池来执行数据
    pool->start(pTask);
}
