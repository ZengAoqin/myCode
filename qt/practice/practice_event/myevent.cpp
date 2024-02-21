#include "myevent.h"
#include "ui_myevent.h"

MyEvent::MyEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyEvent)
{
    ui->setupUi(this);
}

MyEvent::~MyEvent()
{
    delete ui;
}

bool MyEvent::event(QEvent *event)
{
    static int num = 0;
    qDebug() << "no." << ++num << event->type();

    return QWidget::event(event);
}

//按下鼠标
void MyEvent::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "按下鼠标:" << event->pos();
}

//松开鼠标
void MyEvent::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "松开鼠标:" << event->pos();
}

//双击鼠标
void MyEvent::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(this->isFullScreen())
    {
        this->showNormal();
    }
    else
    {
        this->showFullScreen();
    }
}

//按下键盘
void MyEvent::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Escape:
        {
            this->showNormal();
            break;
        }
        case Qt::Key_Return:
        {
            qDebug() << "Enter pressed";
            break;
        }
        case Qt::Key_Space:
        {
            this->showFullScreen();
            break;
        }
    }

}

//鼠标进入窗口
void MyEvent::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("background-color: rgb(228, 255, 165)");
}

//鼠标离开窗口
void MyEvent::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setStyleSheet("background-color: rgb(235, 116, 255)");
}
