#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include "config.h"
#include "bullet.h"

//����Ӣ�۷ɻ���
class HeroPlane
{
public:
    HeroPlane();            //���캯��

    void shoot();            //�����ӵ�

    void setPosition(int x, int y);     //���÷ɻ�������
    void getPosition(int& x, int& y);   //��ȡ�ɻ�������

    int width() const;                  //��ȡ�ɻ��Ŀ��
    int height() const;                 //��ȡ�ɻ��ĸ߶�

    void setHeroSpeed(int speed);       //���÷ɻ����ٶ�
    int getHeroSpeed() const;           //��ȡ�ɻ����ٶ�

    //�ɻ�����Դ ����
    QPixmap m_Plane;

    //������޵���Դ����
    QPixmap m_Invi;

    //Ӣ�۷ɻ��ľ��α߿�
    QRect m_Rect;

    //����
    Bullet m_bullet[BULLET_NUM];

    //��������¼
    int m_recorder;
private:
    //�ɻ�������
    int m_X;
    int m_Y;
    int m_Speed;
};

#endif // HEROPLANE_H
