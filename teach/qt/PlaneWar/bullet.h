#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include "config.h"

//�����ӵ���
class Bullet
{
public:
    Bullet();           //���캯��

    void updatePosition();          //�����ӵ�������
public:
    //�ӵ���Դ����
    QPixmap m_Bullet;
    //�ӵ�������
    int m_X;
    int m_Y;
    //�ӵ����ٶ�
    int m_Speed;
    //�ӵ���״̬
    bool m_Free;
    //�ӵ��ľ��α߿�������ײ��⣩
    QRect m_Rect;
};

#endif // BULLET_H
