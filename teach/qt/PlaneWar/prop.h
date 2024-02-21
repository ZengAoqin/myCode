#ifndef PROP_H
#define PROP_H
#include <QObject>
#include <QPixmap>
#include "config.h"

//道具类
class Prop : public QObject
{
    Q_OBJECT
public:
    Prop(QObject* parent = nullptr);            //构造函数
    void setType(int type);     //设置道具类型
    int getType() const;        //获取道具类型
    void updatePosition();      //更新坐标
    int width() const;          //道具的宽度
    int height() const;         //道具的高度
    void setPosition(int x, int y);     //设置敌机的坐标
    void getPosition(int& x, int& y);   //获取第几的坐标
signals:
    void PropFree();            //道具出屏幕
public:
    //道具的坐标
    int m_X;
    int m_Y;
    //道具是否空闲
    bool m_Free;
    //检测是否碰撞
    QRect m_Rect;
    //道具的移动速度
    int m_Speed;
    //道具的类型
    int m_Type;

    //道具的资源
    QPixmap m_prop;
};

#endif // PROP_H
