#ifndef HEROPLANE_H
#define HEROPLANE_H
#include <QPixmap>
#include "config.h"
#include "bullet.h"

//定义英雄飞机类
class HeroPlane
{
public:
    HeroPlane();            //构造函数

    void shoot();            //发射子弹

    void setPosition(int x, int y);     //设置飞机的坐标
    void getPosition(int& x, int& y);   //获取飞机的坐标

    int width() const;                  //获取飞机的宽度
    int height() const;                 //获取飞机的高度

    //飞机的资源 对象
    QPixmap m_Plane;

    //英雄飞机的矩形边框
    QRect m_Rect;

    //弹夹
    Bullet m_bullet[BULLET_NUM];

    //发射间隔记录
    int m_recorder;
private:
    //飞机的坐标
    int m_X;
    int m_Y;
};

#endif // HEROPLANE_H
