#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QWidget>
#include <QDebug>
//#include <QEvent>       //�¼���

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

    //�¼��ӿ�
    bool event(QEvent* event);
    virtual void mousePressEvent(QMouseEvent* event);   //��갴��
    virtual void mouseReleaseEvent(QMouseEvent* event); //����ɿ�
    virtual void mouseDoubleClickEvent(QMouseEvent* event); //���˫��
    virtual void keyPressEvent(QKeyEvent* event);   //���̰���
    virtual void enterEvent(QEvent* event);         //�����봰��
    virtual void leaveEvent(QEvent* event);         //����뿪����




private:
    Ui::EventWindow* ui;
};

#endif // EVENTWINDOW_H
