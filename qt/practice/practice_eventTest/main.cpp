#include <QApplication>         //应用程序类
#include <QPushButton>          //按钮
#include <QMouseEvent>          //鼠标事件
#include <QDebug>

#define C_S(x) QString::fromLocal8Bit(x)
//子类继承按钮类，重写特定的事件处理
class MyButton: public QPushButton
{
public:
    //构造函数
    explicit MyButton(const QString& text, QWidget* parent = nullptr):
        QPushButton(text, parent) {}
    //重写MyButton中所有的事件的处理函数
    bool event(QEvent* event)
    {
        //根据事件的类型判断自定义的处理对象
        QEvent::Type type = event->type();
        switch(type)
        {
            case QEvent::MouseButtonPress: //鼠标按下
            {
                qDebug() << C_S("事件总接口的鼠标按下+++++++++");
                break;
            }
            case QEvent::MouseMove: //鼠标移动
            {
                qDebug() << C_S("事件总接口的鼠标移动==========");
                break;
            }
            default:
                break;
        }

        //再调用基类对应的处理函数，保证时间处理流程完成
        return QPushButton::event(event);
    }
    //重写鼠标按下事件（特定事件）的处理函数
    virtual void mousePressEvent(QMouseEvent* event)
    {
        //编写鼠标按下的自定义处理
        qDebug() << C_S("---捕获到QEvent::mousePressEvent");
        qDebug() << event->pos(); //获取到坐标数据 x() y()

        //再调用基类对应的处理函数，保证时间处理流程完成
        return QPushButton::mousePressEvent(event);
    }

    //重写鼠标移动事件（特定事件）的处理函数
    void mouseMoveEvent(QMouseEvent* event)
    {
        //编写鼠标按下的自定处理
        qDebug() << C_S("---捕获到QEvent::mouseMoveEvent");
        qDebug() << event->pos(); //获取到坐标数据 x() y()
        if(event->x() > 90 && event->x() < 300) //范围判断
        {
            this->showFullScreen();
        }
        else
        {
            this->showNormal();
        }

        //再调用基类对应的处理函数，保证时间处理流程完成
        return QPushButton::mouseMoveEvent(event);
    }
};

//重写应用程序类QApplication
class MyApplication : public QApplication
{
public:
    //构造函数
    MyApplication(int& argc, char** argv): QApplication(argc, argv) {}
    virtual ~MyApplication() {}
    //重写notify函数

    virtual bool notify(QObject* receiver, QEvent* event)
    {
        //捕获关心的事件
        QEvent::Type type = event->type();
        switch(type)
        {
            case QEvent::MouseButtonDblClick:   //双击事件
            {
                qDebug() << C_S("捕获到了鼠标双击事件");
                break;
            }
            default:
                break;
        }

        //再调用基类同名的处理函数
        return QApplication::notify(receiver, event);
    }

};

//观察者 继承QObject
class Obser : public QObject
{
public:
    //构造函数
    explicit Obser(QObject* parent = nullptr): QObject(parent) {}

    //重写事件过滤器

    virtual bool eventFilter(QObject* watched, QEvent* event)
    {
        //对关心的事件做处理
        QEvent::Type type = event->type();
        switch(type)
        {
            case QEvent::MouseButtonPress:
            {
                qDebug() << C_S("获取观察者的鼠标点击");
                break;
            }
            default:
                break;

        }

        if(type == QEvent::MouseButtonPress)
        {
            return false;       //继续往下传递
            //return true;      //不会往下传递
        }

        //调用基类中的响应处理函数
        return QObject::eventFilter(watched, event);
    }
};

int main(int argc, char* argv[])
{
    //实例化应用程序的对象
    QApplication app(argc, argv);
    //MyApplication app(argc, argv);

    //实例化按钮
    //QPushButton button(C_S("点我"));
    MyButton button(C_S("点我"));
    button.resize(200, 100);

    //定义观察者
    Obser ob;
    //安装过滤器
    button.installEventFilter(&ob);

    //展示按钮
    button.show();

    //保证循环事件
    return app.exec();
}
