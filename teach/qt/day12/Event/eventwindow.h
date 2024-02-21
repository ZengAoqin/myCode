#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QWidget>
#include <QDebug>
//#include <QEvent>       //事件类

namespace Ui
{
class EventWindow;
}

class EventWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EventWindow(QWidget* parent = nullptr);
    ~EventWindow();

    //事件接口
    bool event(QEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);   //鼠标按下
    virtual void mouseReleaseEvent(QMouseEvent* event); //鼠标松开
    virtual void mouseDoubleClickEvent(QMouseEvent* event); //鼠标双击
    virtual void keyPressEvent(QKeyEvent* event);   //键盘按下
    virtual void enterEvent(QEvent* event);         //鼠标进入窗口
    virtual void leaveEvent(QEvent* event);         //鼠标离开窗口




private:
    Ui::EventWindow* ui;
};

#endif // EVENTWINDOW_H
