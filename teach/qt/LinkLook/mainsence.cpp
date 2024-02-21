#include "mainsence.h"

MainSence::MainSence(QWidget* parent) : QWidget(parent)
{
    //设置窗口的标题
    setWindowTitle(CZ(GAME_TITLE));

    //初始化窗口的大小
    setFixedSize(BG_WIDTH * COL_COUNT, BG_HEIGHT * ROW_COUNT);

    //随机数种子
    srand(time(NULL));

    randFruitData();
    initFruitData();
    playBGM();
    m_nClickedCount = 0;
    m_timer.setInterval(10);
    connect(&m_timer, &QTimer::timeout, this, &MainSence::on_timeout);
    m_timer.start();
}

//鼠标按下事件
void MainSence::mousePressEvent(QMouseEvent* event)
{
    Qt::MouseButton btnType = event->button();
    switch(btnType)
    {
        case Qt::LeftButton:    //左键点击
        {
            ++m_nClickedCount;
            qDebug() << CZ("鼠标左键点击");
            m_nClickedCount %= 2;
            int nR = event->x() / BG_WIDTH;
            int nC = event->y() / BG_HEIGHT;
            if(m_nClickedCount)
            {
                m_point1.setX(nC);
                m_point1.setY(nR);
            }
            else
            {
                m_point2.setX(nC);
                m_point2.setY(nR);
            }
            break;
        }
        default:
            break;
    }

    //如果是偶数次点击
    if(gameMap[m_point1.x()][m_point1.y()] == gameMap[m_point2.x()][m_point2.y()])
    {
        qDebug() << CZ("清除");
        //qDebug() << CZ("清除 坐标1") << m_point1.x() << m_point1.y();
        //qDebug() << CZ("清除 坐标2") << m_point2.x() << m_point2.y();
        int index = 0;
        foreach(Fruit fruit, m_fruit)
        {
            qDebug() << CZ("坐标1") << fruit.m_X << fruit.m_Y;
            if(fruit.m_X == m_point1.x()*BG_WIDTH && fruit.m_Y == m_point1.y()*BG_HEIGHT)
            {
                qDebug() << CZ("找到坐标1");
                m_fruit[index].setFreeStatus(true);
                //fruit.setFreeStatus(true);
            }

            if(fruit.m_X == m_point2.x()*BG_WIDTH && fruit.m_Y == m_point2.y()*BG_HEIGHT)
            {
                qDebug() << CZ("找到坐标2");
                m_fruit[index].setFreeStatus(true);
                //fruit.setFreeStatus(true);
            }
            index++;
        }
    }
}

//绘制事件
void MainSence::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)
    drawBackGroup();
    drawFruit();
}

void MainSence::on_timeout()
{
    //刷新数据
    update();
}

//绘画背景图
void MainSence::drawBackGroup()
{
    QPainter painter(this);
    int i, j;
    for(i = 0; i < ROW_COUNT; ++i)
    {
        for(j = 0; j < COL_COUNT; ++j)
        {
            QPixmap bgRes(GAME_BG_PATH);
            painter.drawPixmap(j * BG_WIDTH, i * BG_HEIGHT, BG_WIDTH, BG_HEIGHT, bgRes);
        }
    }
}

void MainSence::drawFruit()
{
    QPainter painter(this);
    foreach(Fruit fruit, m_fruit)
    {
        if(!fruit.getFreeStatus())
        {
            painter.drawPixmap(fruit.m_X, fruit.m_Y, BG_WIDTH, BG_HEIGHT, fruit.m_Res);
        }
    }
}

//初始化水果数据
void MainSence::initFruitData()
{

    int i, j;
    QString strRes;
    for(i = 0; i < ROW_COUNT; ++i)
    {
        for(j = 0; j < COL_COUNT; ++j)
        {
            Fruit fruit;
            strRes = QString(":/res/res/%1.png").arg(gameMap[i][j] + 1);
            if(!fruit.loadResource(strRes))
            {
                qDebug() << CZ("加载水果资源失败") << strRes;
            }
            fruit.setFreeStatus(false);
            fruit.m_X = j * BG_WIDTH;
            fruit.m_Y = i * BG_HEIGHT;
            m_fruit.push_back(fruit);
        }
    }
}

//乱序数据
void MainSence::randFruitData()
{
    QVector<int> v;
    int i, j;
    for(i = 0; i < ROW_COUNT * COL_COUNT / 4; ++i)
    {
        for(j = 0; j < 4; ++j)
        {
            v.push_back(i);
        }
    }

    //乱序
    int index;
    for(i = 0; i < ROW_COUNT * COL_COUNT; ++i) //0~159
    {
        index = std::rand() % v.size();
        gameMap[i / COL_COUNT][i % COL_COUNT] = v[index];

        //将使用过的数据删除
        v.erase(v.begin() + index);
    }
}

void MainSence::playBGM()
{
    //播放音效
    //C:/Users/RD/Desktop/Share/QT/day13/build-LinkLook-Desktop_Qt_5_12_0_MinGW_64_bit-Debug
    QSound::play("C:/Users/RD/Desktop/Share/QT/day13/LinkLook/sound/bg.wav");
}
