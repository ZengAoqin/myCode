#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QDebug>
#include <QVector>
#include <QSound>
#include <QTimer>
#include "config.h"
#include "fruit.h"

class MainSence : public QWidget
{
    Q_OBJECT
public:
    explicit MainSence(QWidget* parent = nullptr);

protected:
    virtual void mousePressEvent(QMouseEvent* event);   //鼠标按下事件
    virtual void paintEvent(QPaintEvent* event);        //绘制事件
signals:

private slots:
    void on_timeout();
private:
    //绘画背景图
    void drawBackGroup();
    //绘画水果图
    void drawFruit();
    //初始化水果数据
    void initFruitData();
    //乱序数据
    void randFruitData();
    //播放背景音乐
    void playBGM();
private:
    QVector<Fruit> m_fruit; //容器存储水果数据
    //定义两个坐标
    QPoint m_point1;
    QPoint m_point2;
    //辅助判断是第几次点击
    int m_nClickedCount;
    //定义定时器对象
    QTimer m_timer;
};

#endif // MAINSENCE_H
