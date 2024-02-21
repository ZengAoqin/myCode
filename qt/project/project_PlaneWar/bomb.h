#ifndef BOMB_H
#define BOMB_H
#include <QVector>
#include <QPixmap>
#include "config.h"

//定义爆炸类
class Bomb
{
public:
    Bomb();

    void updateInfo();          //更新爆炸信息(播放图片下标，播放间隔)
public:
    //放爆炸资源容器
    QVector<QPixmap> m_pixArr;

    //爆炸的坐标
    int m_X;
    int m_Y;

    //爆炸状态
    bool m_Free;

    //爆炸切图的时间间隔
    int m_Recoder;

    //爆炸时加载的图片下标
    int m_Index;
};

#endif // BOMB_H
