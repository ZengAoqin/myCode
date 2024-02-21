#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QTime>
#include <QSound>                //����
#include <QMediaPlayer>          //��ý��
#include "config.h"
#include "map.h"                //��ͼ
#include "heroplane.h"          //Ӣ�۷ɻ�
#include "enemyplane.h"         //�л�
#include "bomb.h"               //��ը
#include "prop.h"               //����

class MainScene : public QWidget
{
    Q_OBJECT
public:
    explicit MainScene(QWidget* parent = nullptr);          //���캯��
    ~MainScene();                                           //��������

    void initScene();                                       //��ʼ������
    void gameStart();                                       //��Ϸ��ʼ
    void gameOver();                                        //��Ϸ����

signals:
    void modifyProp(int);                                      //��Ϸ�ӳ�

public slots:


private slots:
    void mapmove();
    void resetProp();
    void onModifyProp(int prop);
    void propCannel();                                      //���߼ӳɽ���
protected:
    virtual void paintEvent(QPaintEvent* event);            //���ػ����麯��

    virtual void keyPressEvent(QKeyEvent* event);           //���ؼ��̰����麯��

    virtual void mousePressEvent(QMouseEvent* event);       //������갴���麯��
private:
    void enemyToScene();                                    //�л�����
    void propToScene();                                     //���߳���
    void collisionDetection();                              //��ײ���

private:
    //��ʱ������
    QTimer* m_pTimer;
    //�������߼ӳɶ�ʱ��
    QTimer* m_pPropTimer;
    //��ͼ����
    Map m_map;
    //ʵ����Ӣ�۷ɻ�����
    HeroPlane m_hero;
    //�л�����
    EnemyPlane m_enemyArr[ENEMY_NUM];
    //�л����������¼
    int m_enemyRecorder;
    //ʵ�������߶���
    Prop m_prop;
    //���߳��������¼
    int m_propRecorder;
    int m_propRand;         //�����������ʱ��
    int m_propTime;         //���߳���ʱ��
    int m_heroHasProp;      //��0��Ӣ��ս��û�е��� 1��Ӣ��ս�����ٶ� 2��Ӣ��ս�����޵У�
    int m_oldSpeed;         //Ӣ��ս��ԭ�����ٶ�
    int m_score;            //��Ϸ�÷�
    //��ը����
    Bomb m_bombArr[BOMB_NUM];
    //��Ϸ������ʶ
    bool m_gameOver;
};

#endif // MAINSCENE_H
