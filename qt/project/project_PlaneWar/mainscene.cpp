#include "mainscene.h"
#include <ctime>

MainScene::MainScene(QWidget* parent) :
    QWidget(parent), m_pTimer(new QTimer)
{
    //设置窗口的固定大小
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //设置窗口的标题
    setWindowTitle(GAME_TITLE);

    //设置窗口图标
    setWindowIcon(QIcon(GAME_ICON));

    //绑定定时器
    connect(m_pTimer, &QTimer::timeout, this, &MainScene::mapmove);

    //设置定时器的刷新事件
    m_pTimer->setInterval(GAME_RATE);
    m_pTimer->start(); //开启定时器
    m_gameOver = false; //默认开始开始

    m_enemyRecorder = 0;
    //启动背景音乐
    QSound::play("D:/workspace/code/Linux Shared Space/work/qt/project/project_PlaneWar/res/bg.wav");

    //设置随机种子
    srand((unsigned int)time(NULL));
}

//地图移动槽函数
void MainScene::mapmove()
{
    if(m_gameOver)
    {
        return;
    }
    //qDebug() << "响应槽函数mapmove()";
    m_map.mapPosition();


    enemyToScene();

    //发射子弹
    m_hero.shoot();

    int i;
    //计算子弹的坐标
    for(i = 0; i < BULLET_NUM; ++i)
    {
        if(!m_hero.m_bullet[i].m_Free)
        {
            m_hero.m_bullet[i].updatePosition();
        }
    }

    //计算敌机的坐标
    for(i = 0; i < ENEMY_NUM; ++i)
    {
        if(!m_enemyArr[i].m_Free)
        {
            m_enemyArr[i].updatePosition();
        }
    }

    //碰撞检测
    collisionDetection();

    //计算爆炸播放的图片
    for(i = 0; i < BOMB_NUM; ++i)
    {
        if(!m_bombArr[i].m_Free)
        {
            m_bombArr[i].updateInfo();
        }
    }

    update();    //再调用刷新
}

void MainScene::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    if(m_gameOver) //游戏结束
    {
        QPixmap gameOver;
        gameOver.load(GAME_OVER);
        painter.drawPixmap(0, 0, gameOver);
    }
    else
    {
        //绘制地图
        painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
        painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

        //绘制英雄飞机
        int x = 0, y = 0;
        m_hero.getPosition(x, y); //获取飞机的坐标
        painter.drawPixmap(x, y, m_hero.m_Plane);

        int i = 0;
        //绘制子弹
        for(i = 0; i < BULLET_NUM; ++i)
        {
            if(!m_hero.m_bullet[i].m_Free)
            {
                painter.drawPixmap(m_hero.m_bullet[i].m_X - 60, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
                painter.drawPixmap(m_hero.m_bullet[i].m_X - 40, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
                painter.drawPixmap(m_hero.m_bullet[i].m_X - 20, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
                painter.drawPixmap(m_hero.m_bullet[i].m_X + 20, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
                painter.drawPixmap(m_hero.m_bullet[i].m_X + 40, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
                painter.drawPixmap(m_hero.m_bullet[i].m_X + 60, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
            }
        }

        //绘制敌机
        for(i = 0; i < ENEMY_NUM; ++i)
        {
            if(!m_enemyArr[i].m_Free)
            {
                m_enemyArr[i].getPosition(x, y);
                painter.drawPixmap(x, y, *m_enemyArr[i].getEnemyPlanePixmap());
            }
        }

        //绘制爆炸图片
        for(i = 0; i < BOMB_NUM; ++i)
        {
            if(!m_bombArr[i].m_Free)
            {
                painter.drawPixmap(m_bombArr[i].m_X, m_bombArr[i].m_Y,
                                   m_bombArr[i].m_pixArr[m_bombArr[i].m_Index]);
            }
        }
    }
}

//键盘处理事件
void MainScene::keyPressEvent(QKeyEvent* event)
{
    int x = 0, y = 0;
    m_hero.getPosition(x, y); //获取飞机的坐标
    //获取飞机宽度和高度
    int width = m_hero.width(), height = m_hero.height();
    switch(event->key())
    {
        case Qt::Key_Up: //上
        {
            y -= HERO_MOVE_DISTANCE;
            break;
        }
        case Qt::Key_Down: //下
        {
            y += HERO_MOVE_DISTANCE;
            break;
        }
        case Qt::Key_Left:  //左
        {
            x -= HERO_MOVE_DISTANCE;
            break;
        }
        case Qt::Key_Right: //右
        {
            x += HERO_MOVE_DISTANCE;
            break;
        }
        default:
        {
            //不处理其他的按键消息
            break;
        }
    }

    //边界检测
    if(x <= 0)
    {
        x = 0;
    }
    else if(x >= GAME_WIDTH - width)
    {
        x = GAME_WIDTH - width;
    }

    if(y <= 0)
    {
        y = 0;
    }
    else if(y >= GAME_HEIGHT - height)
    {
        y = GAME_HEIGHT - height;
    }

    m_hero.setPosition(x, y);
}

void MainScene::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        //m_hero.shoot();
        qDebug() << "鼠标左键点击";
    }
}

//敌机出场
void MainScene::enemyToScene()
{
    //累加出场间隔
    m_enemyRecorder ++;
    if(m_enemyRecorder < ENEMY_INTERVAL)
    {
        return;
    }

    m_enemyRecorder = 0;

    int i = 0, x = 0, y = 0;
    for(i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemyArr[i].m_Free)
        {
            m_enemyArr[i].m_Free = false;
            //设置坐标
            x = rand() % (GAME_WIDTH - m_enemyArr[i].width());
            y = -m_enemyArr[i].height();
            m_enemyArr[i].setPosition(x, y);
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    int i = 0, j = 0, k = 0;
    int x = 0, y = 0;
    for(i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemyArr[i].m_Free)
        {
            continue;
        }

        //判断子弹是否击中敌机
        for(j = 0; j < BULLET_NUM; ++j)
        {
            if(m_hero.m_bullet[j].m_Free)
            {
                continue;
            }

            if(m_enemyArr[i].m_Rect.intersects(m_hero.m_bullet[j].m_Rect))
            {
                //播放音效
                QSound::play("D:/share/qt/project/project_PlaneWar/res/bomb.wav");
                //将碰撞的子弹和敌机设置为空闲
                m_enemyArr[i].m_Free = true;
                m_hero.m_bullet[j].m_Free = true;

                //调用爆炸的特效
                //播放爆炸效果
                for(k = 0; k < BOMB_NUM; ++k)
                {
                    if(m_bombArr[k].m_Free)
                    {
                        //将爆炸状态设置为非空闲
                        m_bombArr[k].m_Free = false;
                        m_enemyArr[i].getPosition(x, y);
                        //更新坐标
                        m_bombArr[k].m_X = x;
                        m_bombArr[k].m_Y = y;
                        break;
                    }
                }
            }
        }
    }

    //遍历所有非空闲的敌机
    for(i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemyArr[i].m_Free) //空闲飞机 跳转到下一次循环
        {
            continue;
        }

        //如果敌机和英雄飞机矩形框相交，发生了碰撞
        if(m_enemyArr[i].m_Rect.intersects(m_hero.m_Rect))
        {
            //播放音效
            QSound::play("D:/workspace/code/Linux Shared Space/work/qt/project/project_PlaneWar/res/bomb.wav");
            // 此时游戏结束
            m_gameOver = true;
        }
    }

    if(m_gameOver)
    {
        //游戏结束关闭定时器
        m_pTimer->stop();
    }
}

MainScene::~MainScene()
{
    delete m_pTimer;
}
