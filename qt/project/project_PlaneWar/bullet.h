#ifndef BULLET_H
#define BULLET_H
#include <QPixmap>
#include "config.h"

//定义子弹类
class Bullet
{
public:
    Bullet();           //构造函数

    void updatePosition();          //跟新子弹的坐标
public:
    //子弹资源对象
    QPixmap m_Bullet;
    //子弹的坐标
    int m_X;
    int m_Y;
    //子弹的速度
    int m_Speed;
    //子弹的状态
    bool m_Free;
    //子弹的矩形边框（用于碰撞检测）
    QRect m_Rect;
};

#endif // BULLET_H
