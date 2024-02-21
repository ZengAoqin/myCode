#ifndef MYEVENT_H
#define MYEVENT_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>


namespace Ui {
class MyEvent;
}

class MyEvent : public QWidget
{
    Q_OBJECT

public:
    explicit MyEvent(QWidget *parent = nullptr);
    ~MyEvent();

    //事件接口
    virtual bool event(QEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void keyPressEvent(QKeyEvent* event);
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);

private:
    Ui::MyEvent *ui;
};

#endif // MYEVENT_H
