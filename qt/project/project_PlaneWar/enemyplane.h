#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include "config.h"
#include <QDebug>

//敌机类
class EnemyPlane
{
public:
    EnemyPlane();   //构造函数
    ~EnemyPlane();  //析构函数
    void updatePosition();  //自动更新坐标

    void setPosition(int x, int y);     //设置敌机的坐标
    void getPosition(int& x, int& y);   //获取第几的坐标

    int width() const;      //获取敌机的宽度
    int height() const;     //获取敌机的高度

    QPixmap* getEnemyPlanePixmap() const;     //获取敌机资源指针

    //状态
    bool m_Free;
    //敌机的矩形边框（用于碰撞检测）
    QRect m_Rect;
private:
    //敌机资源对象
    QPixmap* m_pEnemy;

    //坐标
    int m_X;
    int m_Y;

    //速度
    int m_Speed;
};

#endif // ENEMYPLANE_H
