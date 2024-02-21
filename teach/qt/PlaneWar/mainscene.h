#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QTime>
#include <QSound>                //声音
#include <QMediaPlayer>          //多媒体
#include "config.h"
#include "map.h"                //地图
#include "heroplane.h"          //英雄飞机
#include "enemyplane.h"         //敌机
#include "bomb.h"               //爆炸
#include "prop.h"               //道具

class MainScene : public QWidget
{
    Q_OBJECT
public:
    explicit MainScene(QWidget* parent = nullptr);          //构造函数
    ~MainScene();                                           //析构函数

    void initScene();                                       //初始化场景
    void gameStart();                                       //游戏开始
    void gameOver();                                        //游戏结束

signals:
    void modifyProp(int);                                      //游戏加成

public slots:


private slots:
    void mapmove();
    void resetProp();
    void onModifyProp(int prop);
    void propCannel();                                      //道具加成结束
protected:
    virtual void paintEvent(QPaintEvent* event);            //重载绘制虚函数

    virtual void keyPressEvent(QKeyEvent* event);           //重载键盘按下虚函数

    virtual void mousePressEvent(QMouseEvent* event);       //重载鼠标按下虚函数
private:
    void enemyToScene();                                    //敌机出场
    void propToScene();                                     //道具出场
    void collisionDetection();                              //碰撞检测

private:
    //定时器对象
    QTimer* m_pTimer;
    //开启道具加成定时器
    QTimer* m_pPropTimer;
    //地图对象
    Map m_map;
    //实例化英雄飞机对象
    HeroPlane m_hero;
    //敌机数组
    EnemyPlane m_enemyArr[ENEMY_NUM];
    //敌机出场间隔记录
    int m_enemyRecorder;
    //实例化道具对象
    Prop m_prop;
    //道具出场间隔记录
    int m_propRecorder;
    int m_propRand;         //道具随机出场时间
    int m_propTime;         //道具持续时间
    int m_heroHasProp;      //（0：英雄战机没有道具 1：英雄战机有速度 2：英雄战机有无敌）
    int m_oldSpeed;         //英雄战机原来的速度
    int m_score;            //游戏得分
    //爆炸数组
    Bomb m_bombArr[BOMB_NUM];
    //游戏结束标识
    bool m_gameOver;
};

#endif // MAINSCENE_H
