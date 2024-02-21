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
    //����ϵͳԭ�еĽӿڣ����¼���Ч
    return QWidget::event(event);
}

void EventWindow::mousePressEvent(QMouseEvent* event)
{
    qDebug() << C_Z("��갴�²���") << event->pos();
}

void EventWindow::mouseReleaseEvent(QMouseEvent* event)
{
    qDebug() << C_Z("����ɿ�����") << event->pos();
}

void EventWindow::mouseDoubleClickEvent(QMouseEvent* event)
{
    //�жϵ�ǰ�����Ƿ���ʾȫ��
    if(this->isFullScreen())
    {
        this->showNormal(); //��ʾΪԭ���Ĵ��ڳߴ�
    }
    else
    {
        this->showFullScreen(); //��ʾȫ��
    }
}

void EventWindow::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        case Qt::Key_Escape: //Esc��
        {
            this->showNormal();
            break;
        }
        case Qt::Key_Return: //�س���
        case Qt::Key_Space://�ո��
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
