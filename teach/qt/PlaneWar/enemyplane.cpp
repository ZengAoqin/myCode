#include "enemyplane.h"

EnemyPlane::EnemyPlane(): m_pEnemy(new QPixmap(ENEMY_PLANE_PATH))
{
    //���صл���Դ
    //m_enemy.load(ENEMY_PLANE_PATH);

    //��ʼ���л�������
    m_X = 0;
    m_Y = 0;

    //�л���״̬
    m_Free = true;

    //�л����ٶ�
    m_Speed = ENEMY_SPEED;

    //�л����α߿����ڼ����ײ��
    m_Rect.setWidth(m_pEnemy->width());
    m_Rect.setHeight(m_pEnemy->height());
    m_Rect.moveTo(m_X, m_Y);
}

EnemyPlane::~EnemyPlane()
{
    delete m_pEnemy;
}

void EnemyPlane::updatePosition()
{
    //�жϵл��Ƿ��ǿ���״̬
    if(m_Free)
    {
        return;
    }

    m_Y += m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if(m_Y >= GAME_HEIGHT)
    {
        m_Free = true;
    }
}

void EnemyPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X, m_Y);
}

void EnemyPlane::getPosition(int& x, int& y)
{
    x = m_X;
    y = m_Y;
}

int EnemyPlane::width() const
{
    return m_pEnemy->width();
}

int EnemyPlane::height() const
{
    return m_pEnemy->height();
}

QPixmap* EnemyPlane::getEnemyPlanePixmap() const
{
    return m_pEnemy;
}

