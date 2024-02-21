#include "eventwindow.h"
#include "ui_eventwindow.h"
#include <QMouseEvent>
#define C_Z(x) QString::fromLocal8Bit(x)

EventWindow::EventWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);
}

EventWindow::~EventWindow()
{
    delete ui;
}

bool EventWindow::event(QEvent* event)
{

    static int num = 0;
    //qDebug() << "num: " << num;
    //调用系统原有的接口，让事件生效
    return QWidget::event(event);
}

void EventWindow::mousePressEvent(QMouseEvent* event)
{
    qDebug() << C_Z("鼠标按下操作") << event->pos();
}

void EventWindow::mouseReleaseEvent(QMouseEvent* event)
{
    qDebug() << C_Z("鼠标松开操作") << event->pos();
}

void EventWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
    //判断当前窗口是否显示全屏
    if(this->isFullScreen())
    {
        this->showNormal(); //显示为原来的窗口尺寸
    }
    else
    {
        this->showFullScreen(); //显示全屏
    }
}

void EventWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_Escape: //Esc键
        {
            this->showNormal();
            break;
        }
        case Qt::Key_Return: //回车键
        case Qt::Key_Space://空格键
        {
            this->showFullScreen();
            break;
        }
        default:
            break;
    }

}

void EventWindow::enterEvent(QEvent* event)
{
    //this->setStyleSheet("background-color: rgb(85, 255, 0)");
    this->setStyleSheet("background-color: #acc5ff");
    //#acc5ff
}

void EventWindow::leaveEvent(QEvent* event)
{
    this->setStyleSheet("background-color: rgb(85, 255, 0)");
}
