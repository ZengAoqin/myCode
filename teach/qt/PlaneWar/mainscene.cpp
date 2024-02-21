#include "mainscene.h"
#include <ctime>
#include <QDebug>

//构造函数
MainScene::MainScene(QWidget* parent) :
    QWidget(parent), m_pTimer(new QTimer), m_pPropTimer(new QTimer)
{
    //初始化游戏场景
    initScene();
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

    //敌机出场
    enemyToScene();

    //道具出场
    propToScene();

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

    //计算爆炸播放的图片
    for(i = 0; i < BOMB_NUM; ++i)
    {
        if(!m_bombArr[i].m_Free)
        {
            m_bombArr[i].updateInfo();
        }
    }

    //计算道具的坐标
    if(!m_prop.m_Free)
    {
        m_prop.updatePosition();
    }

    //计算道具的续航时间

    update();    //再调用刷新
    //碰撞检测
    collisionDetection();
}

void MainScene::resetProp()
{
    //重新设置道具出场时间
    m_propRand = rand() % 6 + 5;    //道具随机出场时间是5~10
    //int typeProp = rand() % 2 + 1;  //道具类型
    int typeProp = 2;
    m_prop.setType(typeProp);       //设置道具类型
    m_propRecorder = 0;
    propToScene();
}

void MainScene::onModifyProp(int prop)
{
    m_heroHasProp = prop;
    m_pPropTimer->start();
}

void MainScene::propCannel()
{
    //此时道具加成结束，设置为普通状态
    m_heroHasProp = 0;
    m_pPropTimer->stop();
}

//绘制
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

        //显示得分区域
        QString setScore = QString::number(m_score);
        const QRect rectangle = QRect(0, 0, 50, 100);
        QRect bandingRect;
        painter.drawText(rectangle, 0, setScore, &bandingRect);
        QPen pen = painter.pen();
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        pen.setColor(Qt::red);
        painter.drawRect(bandingRect.adjusted(0, 0, -pen.width(), -pen.width()));

        //绘制英雄飞机
        int x = 0, y = 0;
        m_hero.getPosition(x, y); //获取飞机的坐标
        if(m_heroHasProp == 2)  //如果有无敌加成
        {
            painter.drawPixmap(x, y, m_hero.m_Invi);
        }
        painter.drawPixmap(x, y, m_hero.m_Plane);

        int i = 0;
        //绘制子弹
        for(i = 0; i < BULLET_NUM; ++i)
        {
            if(!m_hero.m_bullet[i].m_Free)
            {
                painter.drawPixmap(m_hero.m_bullet[i].m_X, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
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

        //绘制道具
        if(!m_prop.m_Free)
        {
            //绘制道具
            painter.drawPixmap(m_prop.m_X, m_prop.m_Y, m_prop.m_prop);
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
    int speed = m_hero.getHeroSpeed(); //获取飞机的速度
    switch(event->key())
    {
        case Qt::Key_Up: //上
        {
            y -= speed;
            break;
        }
        case Qt::Key_Down: //下
        {
            y += speed;
            break;
        }
        case Qt::Key_Left:  //左
        {
            x -= speed;
            break;
        }
        case Qt::Key_Right: //右
        {
            x += speed;
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

//鼠标事件
void MainScene::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        //m_hero.shoot();
        qDebug() << C_Z("鼠标左键点击");
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

//道具出场
void MainScene::propToScene()
{
    m_propRecorder++;
    if(m_propRecorder < m_propRand * 1000 / GAME_RATE)
    {
        return;
    }
    m_propRecorder = 0;

    int x = 0, y = 0;
    if(m_prop.m_Free)
    {
        m_prop.m_Free = false;
        //设置坐标
        x = rand() % (GAME_WIDTH - m_prop.width());
        y = -m_prop.height();
        m_prop.setPosition(x, y);
        //        int typeProp = rand() % 2 + 1;  //道具类型
        int typeProp = 2;
        m_prop.setType(typeProp);       //设置道具类型
        qDebug() << C_Z("道具出场") << C_Z("道具类型") << typeProp;
    }
}

//碰撞检测
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
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/bomb.wav");
                //将碰撞的子弹和敌机设置为空闲
                m_enemyArr[i].m_Free = true;
                m_hero.m_bullet[j].m_Free = true;

                m_score += 10;

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
    if(m_heroHasProp != 2)
    {
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
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/bomb.wav");
                // 此时游戏结束
                gameOver();
            }
        }

    }


    //检测道具和英雄飞机是否相交
    if(!m_prop.m_Free)
    {
        if(m_hero.m_Rect.intersects(m_prop.m_Rect))
        {
            //获取游戏加成
            int Prop = m_prop.getType();
            qDebug() << C_Z("游戏加成类型") << Prop;
            if(Prop == 1)
            {
                //播放音效
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/prop_1.wav");
                m_oldSpeed = m_hero.getHeroSpeed();
                m_hero.setHeroSpeed(m_oldSpeed + 5);
            }
            else if(Prop == 2)
            {
                //播放英雄战机无敌的音效
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/invi.wav");
            }
            emit modifyProp(Prop);
            //update();    //再调用刷新

            //让道具消失
            m_prop.m_Free = true;
            //m_propRecorder = 0;
        }
    }

    if(m_gameOver)
    {
        //游戏结束关闭定时器
        m_pTimer->stop();
        //关闭道具加成定时器
        m_pPropTimer->stop();
    }
}

//析构函数
MainScene::~MainScene()
{
    delete m_pTimer;
    delete m_pPropTimer;
}

//初始化 场景
void MainScene::initScene()
{
    //设置窗口的固定大小
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //设置窗口的标题
    setWindowTitle(GAME_TITLE);

    //设置窗口图标
    setWindowIcon(QIcon(GAME_ICON));

    //绑定定时器
    connect(m_pTimer, &QTimer::timeout, this, &MainScene::mapmove);

    //绑定道具
    connect(&m_prop, &Prop::PropFree, this, &MainScene::resetProp);

    //修改游戏加成
    connect(this, SIGNAL(modifyProp(int)), this, SLOT(onModifyProp(int)));

    //绑定加成定时器的持续时间
    connect(m_pPropTimer, &QTimer::timeout, this, &MainScene::propCannel);

    //设置定时器的时间间隔
    m_pTimer->setInterval(GAME_RATE);

    //设置道具加成的时间
    m_pPropTimer->setInterval(4000);

    //调用游戏开始接口
    gameStart();

    //敌机出场记录变量 初始化
    m_enemyRecorder = 0;

    //游戏得分初始化
    m_score = 0;

    //设置随机种子
    srand((unsigned int)time(NULL));
}

//游戏开始
void MainScene::gameStart()
{
    m_gameOver = false; //默认开始开始
    m_pTimer->start(); //开启定时器
    //启动背景音乐
    //m_pPlayer->setMedia(QUrl::fromLocalFile("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/next.mp3"));
    //m_pPlayer->play();
    QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/next.wav");
    m_propRand = rand() % 6 + 5;    //道具随机出场时间是5~10
    m_heroHasProp = 0;              //英雄战机没有任何道具
    m_propTime = PROP_CONTINUE;     //道具续航时间
}

void MainScene::gameOver()
{
    m_gameOver = true;
    m_pTimer->stop();
}
