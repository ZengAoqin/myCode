#ifndef PROP_H
#define PROP_H
#include <QObject>
#include <QPixmap>
#include "config.h"

//������
class Prop : public QObject
{
    Q_OBJECT
public:
    Prop(QObject* parent = nullptr);            //���캯��
    void setType(int type);     //���õ�������
    int getType() const;        //��ȡ��������
    void updatePosition();      //��������
    int width() const;          //���ߵĿ��
    int height() const;         //���ߵĸ߶�
    void setPosition(int x, int y);     //���õл�������
    void getPosition(int& x, int& y);   //��ȡ�ڼ�������
signals:
    void PropFree();            //���߳���Ļ
public:
    //���ߵ�����
    int m_X;
    int m_Y;
    //�����Ƿ����
    bool m_Free;
    //����Ƿ���ײ
    QRect m_Rect;
    //���ߵ��ƶ��ٶ�
    int m_Speed;
    //���ߵ�����
    int m_Type;

    //���ߵ���Դ
    QPixmap m_prop;
};

#endif // PROP_H
