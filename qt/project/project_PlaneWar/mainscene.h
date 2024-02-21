#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QTime>
#include <QSound>               //声音
#include <QMediaPlayer>
#include "config.h"
#include "map.h"                //地图
#include "heroplane.h"          //英雄飞机
#include "enemyplane.h"         //敌机
#include "bomb.h"               //爆炸

class MainScene : public QWidget
{
    Q_OBJECT
public:
    explicit MainScene(QWidget* parent = nullptr);          //构造函数
    ~MainScene();                                           //析构函数

signals:

public slots:

private slots:
    void mapmove();
protected:
    virtual void paintEvent(QPaintEvent* event);            //重载绘制虚函数

    virtual void keyPressEvent(QKeyEvent* event);           //重载键盘按下虚函数

    virtual void mousePressEvent(QMouseEvent* event);       //重载鼠标按下虚函数
private:
    void enemyToScene();                                    //敌机出场
    void collisionDetection();                              //碰撞检测

private:
    //定时器对象
    QTimer* m_pTimer;
    //地图对象
    Map m_map;
    //实例化英雄飞机对象
    HeroPlane m_hero;
    //敌机数组
    EnemyPlane m_enemyArr[ENEMY_NUM];
    //敌机出场间隔记录
    int m_enemyRecorder;
    //爆炸数组
    Bomb m_bombArr[BOMB_NUM];
    //游戏结束标识
    bool m_gameOver;
};

#endif // MAINSCENE_H
