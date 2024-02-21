#ifndef MAP_H
#define MAP_H

#include <QPixmap>
#include "config.h"

//定义地图类
class Map
{
public:
    Map();      //构造函数

    void mapPosition();     //地图滚动坐标计算

    //地图对象图片
    QPixmap m_map1;     //图片1
    QPixmap m_map2;     //图片2

    //地图Y轴坐标
    int m_map1_posY;    //图片1的y轴坐标
    int m_map2_posY;    //图片2的y轴坐标

    //地图的滚动速度
    int m_scroll_speed;
};

#endif // MAP_H
