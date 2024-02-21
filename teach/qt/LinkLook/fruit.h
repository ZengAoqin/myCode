#ifndef FRUIT_H
#define FRUIT_H
#include <QPixmap>

class Fruit
{
public:
    //构造函数
    Fruit();
    //加载资源图片
    bool loadResource(const QString& filename);
    //设置资源状态
    void setFreeStatus(bool bFree);
    //获取状态
    bool getFreeStatus();

    QPixmap m_Res;          //资源图片

    //坐标
    int m_X;                //x轴坐标
    int m_Y;                //y轴坐标

private:
    //状态
    bool m_Free;            //是否空闲
};

#endif // FRUIT_H
