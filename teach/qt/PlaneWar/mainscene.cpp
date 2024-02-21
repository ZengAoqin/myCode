#include "mainscene.h"
#include <ctime>
#include <QDebug>

//���캯��
MainScene::MainScene(QWidget* parent) :
    QWidget(parent), m_pTimer(new QTimer), m_pPropTimer(new QTimer)
{
    //��ʼ����Ϸ����
    initScene();
}

//��ͼ�ƶ��ۺ���
void MainScene::mapmove()
{
    if(m_gameOver)
    {
        return;
    }
    //qDebug() << "��Ӧ�ۺ���mapmove()";
    m_map.mapPosition();

    //�л�����
    enemyToScene();

    //���߳���
    propToScene();

    //�����ӵ�
    m_hero.shoot();

    int i;
    //�����ӵ�������
    for(i = 0; i < BULLET_NUM; ++i)
    {
        if(!m_hero.m_bullet[i].m_Free)
        {
            m_hero.m_bullet[i].updatePosition();
        }
    }

    //����л�������
    for(i = 0; i < ENEMY_NUM; ++i)
    {
        if(!m_enemyArr[i].m_Free)
        {
            m_enemyArr[i].updatePosition();
        }
    }

    //���㱬ը���ŵ�ͼƬ
    for(i = 0; i < BOMB_NUM; ++i)
    {
        if(!m_bombArr[i].m_Free)
        {
            m_bombArr[i].updateInfo();
        }
    }

    //������ߵ�����
    if(!m_prop.m_Free)
    {
        m_prop.updatePosition();
    }

    //������ߵ�����ʱ��

    update();    //�ٵ���ˢ��
    //��ײ���
    collisionDetection();
}

void MainScene::resetProp()
{
    //�������õ��߳���ʱ��
    m_propRand = rand() % 6 + 5;    //�����������ʱ����5~10
    //int typeProp = rand() % 2 + 1;  //��������
    int typeProp = 2;
    m_prop.setType(typeProp);       //���õ�������
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
    //��ʱ���߼ӳɽ���������Ϊ��ͨ״̬
    m_heroHasProp = 0;
    m_pPropTimer->stop();
}

//����
void MainScene::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    if(m_gameOver) //��Ϸ����
    {
        QPixmap gameOver;
        gameOver.load(GAME_OVER);
        painter.drawPixmap(0, 0, gameOver);
    }
    else
    {
        //���Ƶ�ͼ
        painter.drawPixmap(0, m_map.m_map1_posY, m_map.m_map1);
        painter.drawPixmap(0, m_map.m_map2_posY, m_map.m_map2);

        //��ʾ�÷�����
        QString setScore = QString::number(m_score);
        const QRect rectangle = QRect(0, 0, 50, 100);
        QRect bandingRect;
        painter.drawText(rectangle, 0, setScore, &bandingRect);
        QPen pen = painter.pen();
        pen.setStyle(Qt::DashLine);
        painter.setPen(pen);
        pen.setColor(Qt::red);
        painter.drawRect(bandingRect.adjusted(0, 0, -pen.width(), -pen.width()));

        //����Ӣ�۷ɻ�
        int x = 0, y = 0;
        m_hero.getPosition(x, y); //��ȡ�ɻ�������
        if(m_heroHasProp == 2)  //������޵мӳ�
        {
            painter.drawPixmap(x, y, m_hero.m_Invi);
        }
        painter.drawPixmap(x, y, m_hero.m_Plane);

        int i = 0;
        //�����ӵ�
        for(i = 0; i < BULLET_NUM; ++i)
        {
            if(!m_hero.m_bullet[i].m_Free)
            {
                painter.drawPixmap(m_hero.m_bullet[i].m_X, m_hero.m_bullet[i].m_Y, m_hero.m_bullet[i].m_Bullet);
            }
        }

        //���Ƶл�
        for(i = 0; i < ENEMY_NUM; ++i)
        {
            if(!m_enemyArr[i].m_Free)
            {
                m_enemyArr[i].getPosition(x, y);
                painter.drawPixmap(x, y, *m_enemyArr[i].getEnemyPlanePixmap());
            }
        }

        //���Ʊ�ըͼƬ
        for(i = 0; i < BOMB_NUM; ++i)
        {
            if(!m_bombArr[i].m_Free)
            {
                painter.drawPixmap(m_bombArr[i].m_X, m_bombArr[i].m_Y,
                                   m_bombArr[i].m_pixArr[m_bombArr[i].m_Index]);
            }
        }

        //���Ƶ���
        if(!m_prop.m_Free)
        {
            //���Ƶ���
            painter.drawPixmap(m_prop.m_X, m_prop.m_Y, m_prop.m_prop);
        }
    }
}

//���̴����¼�
void MainScene::keyPressEvent(QKeyEvent* event)
{
    int x = 0, y = 0;
    m_hero.getPosition(x, y); //��ȡ�ɻ�������
    //��ȡ�ɻ���Ⱥ͸߶�
    int width = m_hero.width(), height = m_hero.height();
    int speed = m_hero.getHeroSpeed(); //��ȡ�ɻ����ٶ�
    switch(event->key())
    {
        case Qt::Key_Up: //��
        {
            y -= speed;
            break;
        }
        case Qt::Key_Down: //��
        {
            y += speed;
            break;
        }
        case Qt::Key_Left:  //��
        {
            x -= speed;
            break;
        }
        case Qt::Key_Right: //��
        {
            x += speed;
            break;
        }
        default:
        {
            //�����������İ�����Ϣ
            break;
        }
    }

    //�߽���
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

//����¼�
void MainScene::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        //m_hero.shoot();
        qDebug() << C_Z("���������");
    }
}

//�л�����
void MainScene::enemyToScene()
{
    //�ۼӳ������
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
            //��������
            x = rand() % (GAME_WIDTH - m_enemyArr[i].width());
            y = -m_enemyArr[i].height();
            m_enemyArr[i].setPosition(x, y);
            break;
        }
    }
}

//���߳���
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
        //��������
        x = rand() % (GAME_WIDTH - m_prop.width());
        y = -m_prop.height();
        m_prop.setPosition(x, y);
        //        int typeProp = rand() % 2 + 1;  //��������
        int typeProp = 2;
        m_prop.setType(typeProp);       //���õ�������
        qDebug() << C_Z("���߳���") << C_Z("��������") << typeProp;
    }
}

//��ײ���
void MainScene::collisionDetection()
{
    //�������зǿ��еĵл�
    int i = 0, j = 0, k = 0;
    int x = 0, y = 0;
    for(i = 0; i < ENEMY_NUM; ++i)
    {
        if(m_enemyArr[i].m_Free)
        {
            continue;
        }

        //�ж��ӵ��Ƿ���ел�
        for(j = 0; j < BULLET_NUM; ++j)
        {
            if(m_hero.m_bullet[j].m_Free)
            {
                continue;
            }

            if(m_enemyArr[i].m_Rect.intersects(m_hero.m_bullet[j].m_Rect))
            {
                //������Ч
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/bomb.wav");
                //����ײ���ӵ��͵л�����Ϊ����
                m_enemyArr[i].m_Free = true;
                m_hero.m_bullet[j].m_Free = true;

                m_score += 10;

                //���ñ�ը����Ч
                //���ű�ըЧ��
                for(k = 0; k < BOMB_NUM; ++k)
                {
                    if(m_bombArr[k].m_Free)
                    {
                        //����ը״̬����Ϊ�ǿ���
                        m_bombArr[k].m_Free = false;
                        m_enemyArr[i].getPosition(x, y);
                        //��������
                        m_bombArr[k].m_X = x;
                        m_bombArr[k].m_Y = y;
                        break;
                    }
                }
            }
        }
    }

    //�������зǿ��еĵл�
    if(m_heroHasProp != 2)
    {
        for(i = 0; i < ENEMY_NUM; ++i)
        {
            if(m_enemyArr[i].m_Free) //���зɻ� ��ת����һ��ѭ��
            {
                continue;
            }

            //����л���Ӣ�۷ɻ����ο��ཻ����������ײ
            if(m_enemyArr[i].m_Rect.intersects(m_hero.m_Rect))
            {
                //������Ч
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/bomb.wav");
                // ��ʱ��Ϸ����
                gameOver();
            }
        }

    }


    //�����ߺ�Ӣ�۷ɻ��Ƿ��ཻ
    if(!m_prop.m_Free)
    {
        if(m_hero.m_Rect.intersects(m_prop.m_Rect))
        {
            //��ȡ��Ϸ�ӳ�
            int Prop = m_prop.getType();
            qDebug() << C_Z("��Ϸ�ӳ�����") << Prop;
            if(Prop == 1)
            {
                //������Ч
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/prop_1.wav");
                m_oldSpeed = m_hero.getHeroSpeed();
                m_hero.setHeroSpeed(m_oldSpeed + 5);
            }
            else if(Prop == 2)
            {
                //����Ӣ��ս���޵е���Ч
                QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/invi.wav");
            }
            emit modifyProp(Prop);
            //update();    //�ٵ���ˢ��

            //�õ�����ʧ
            m_prop.m_Free = true;
            //m_propRecorder = 0;
        }
    }

    if(m_gameOver)
    {
        //��Ϸ�����رն�ʱ��
        m_pTimer->stop();
        //�رյ��߼ӳɶ�ʱ��
        m_pPropTimer->stop();
    }
}

//��������
MainScene::~MainScene()
{
    delete m_pTimer;
    delete m_pPropTimer;
}

//��ʼ�� ����
void MainScene::initScene()
{
    //���ô��ڵĹ̶���С
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //���ô��ڵı���
    setWindowTitle(GAME_TITLE);

    //���ô���ͼ��
    setWindowIcon(QIcon(GAME_ICON));

    //�󶨶�ʱ��
    connect(m_pTimer, &QTimer::timeout, this, &MainScene::mapmove);

    //�󶨵���
    connect(&m_prop, &Prop::PropFree, this, &MainScene::resetProp);

    //�޸���Ϸ�ӳ�
    connect(this, SIGNAL(modifyProp(int)), this, SLOT(onModifyProp(int)));

    //�󶨼ӳɶ�ʱ���ĳ���ʱ��
    connect(m_pPropTimer, &QTimer::timeout, this, &MainScene::propCannel);

    //���ö�ʱ����ʱ����
    m_pTimer->setInterval(GAME_RATE);

    //���õ��߼ӳɵ�ʱ��
    m_pPropTimer->setInterval(4000);

    //������Ϸ��ʼ�ӿ�
    gameStart();

    //�л�������¼���� ��ʼ��
    m_enemyRecorder = 0;

    //��Ϸ�÷ֳ�ʼ��
    m_score = 0;

    //�����������
    srand((unsigned int)time(NULL));
}

//��Ϸ��ʼ
void MainScene::gameStart()
{
    m_gameOver = false; //Ĭ�Ͽ�ʼ��ʼ
    m_pTimer->start(); //������ʱ��
    //������������
    //m_pPlayer->setMedia(QUrl::fromLocalFile("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/next.mp3"));
    //m_pPlayer->play();
    QSound::play("C:/Users/RD/Desktop/Share/QT/day08/code/build-PlaneWar-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/next.wav");
    m_propRand = rand() % 6 + 5;    //�����������ʱ����5~10
    m_heroHasProp = 0;              //Ӣ��ս��û���κε���
    m_propTime = PROP_CONTINUE;     //��������ʱ��
}

void MainScene::gameOver()
{
    m_gameOver = true;
    m_pTimer->stop();
}
