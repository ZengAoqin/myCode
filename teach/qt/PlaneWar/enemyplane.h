#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include "config.h"
#include <QDebug>

//�л���
class EnemyPlane
{
public:
    EnemyPlane();   //���캯��
    ~EnemyPlane();  //��������
    void updatePosition();  //�Զ���������

    void setPosition(int x, int y);     //���õл�������
    void getPosition(int& x, int& y);   //��ȡ�ڼ�������

    int width() const;      //��ȡ�л��Ŀ��
    int height() const;     //��ȡ�л��ĸ߶�

    QPixmap* getEnemyPlanePixmap() const;     //��ȡ�л���Դָ��

    //״̬
    bool m_Free;
    //�л��ľ��α߿�������ײ��⣩
    QRect m_Rect;
private:
    //�л���Դ����
    QPixmap* m_pEnemy;

    //����
    int m_X;
    int m_Y;

    //�ٶ�
    int m_Speed;
};

#endif // ENEMYPLANE_H
