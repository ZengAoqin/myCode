#include <QApplication>         //Ӧ�ó�����
#include <QPushButton>          //��ť
#include <QMouseEvent>          //����¼�
#include <QDebug>

#define C_S(x) QString::fromLocal8Bit(x)
//����̳а�ť�࣬��д�ض����¼�����
class MyButton: public QPushButton
{
public:
    //���캯��
    explicit MyButton(const QString& text, QWidget* parent = nullptr):
        QPushButton(text, parent) {}
    //��дMyButton�����е��¼��Ĵ�����
    bool event(QEvent* event)
    {
        //�����¼��������ж��Զ���Ĵ������
        QEvent::Type type = event->type();
        switch(type)
        {
            case QEvent::MouseButtonPress: //��갴��
            {
                qDebug() << C_S("�¼��ܽӿڵ���갴��+++++++++");
                break;
            }
            case QEvent::MouseMove: //����ƶ�
            {
                qDebug() << C_S("�¼��ܽӿڵ�����ƶ�==========");
                break;
            }
            default:
                break;
        }

        //�ٵ��û����Ӧ�Ĵ���������֤ʱ�䴦���������
        return QPushButton::event(event);
    }
    //��д��갴���¼����ض��¼����Ĵ�����
    virtual void mousePressEvent(QMouseEvent* event)
    {
        //��д��갴�µ��Զ��崦��
        qDebug() << C_S("---����QEvent::mousePressEvent");
        qDebug() << event->pos(); //��ȡ���������� x() y()

        //�ٵ��û����Ӧ�Ĵ���������֤ʱ�䴦���������
        return QPushButton::mousePressEvent(event);
    }

    //��д����ƶ��¼����ض��¼����Ĵ�����
    void mouseMoveEvent(QMouseEvent* event)
    {
        //��д��갴�µ��Զ�����
        qDebug() << C_S("---����QEvent::mouseMoveEvent");
        qDebug() << event->pos(); //��ȡ���������� x() y()
        if(event->x() > 90 && event->x() < 300) //��Χ�ж�
        {
            this->showFullScreen();
        }
        else
        {
            this->showNormal();
        }

        //�ٵ��û����Ӧ�Ĵ���������֤ʱ�䴦���������
        return QPushButton::mouseMoveEvent(event);
    }
};

//��дӦ�ó�����QApplication
class MyApplication : public QApplication
{
public:
    //���캯��
    MyApplication(int& argc, char** argv): QApplication(argc, argv) {}
    virtual ~MyApplication() {}
    //��дnotify����

    virtual bool notify(QObject* receiver, QEvent* event)
    {
        //������ĵ��¼�
        QEvent::Type type = event->type();
        switch(type)
        {
            case QEvent::MouseButtonDblClick:   //˫���¼�
            {
                qDebug() << C_S("���������˫���¼�");
                break;
            }
            default:
                break;
        }

        //�ٵ��û���ͬ���Ĵ�����
        return QApplication::notify(receiver, event);
    }

};

//�۲��� �̳�QObject
class Obser : public QObject
{
public:
    //���캯��
    explicit Obser(QObject* parent = nullptr): QObject(parent) {}

    //��д�¼�������

    virtual bool eventFilter(QObject* watched, QEvent* event)
    {
        //�Թ��ĵ��¼�������
        QEvent::Type type = event->type();
        switch(type)
        {
            case QEvent::MouseButtonPress:
            {
                qDebug() << C_S("��ȡ�۲��ߵ������");
                break;
            }
            default:
                break;

        }

        if(type == QEvent::MouseButtonPress)
        {
            return false;       //�������´���
            //return true;      //�������´���
        }

        //���û����е���Ӧ������
        return QObject::eventFilter(watched, event);
    }
};

int main(int argc, char* argv[])
{
    //ʵ����Ӧ�ó���Ķ���
    QApplication app(argc, argv);
    //MyApplication app(argc, argv);

    //ʵ������ť
    //QPushButton button(C_S("����"));
    MyButton button(C_S("����"));
    button.resize(200, 100);

    //����۲���
    Obser ob;
    //��װ������
    button.installEventFilter(&ob);


    //չʾ��ť
    button.show();


    //��֤ѭ���¼�
    return app.exec();
}
