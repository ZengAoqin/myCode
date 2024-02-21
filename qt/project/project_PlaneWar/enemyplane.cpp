#include "enemyplane.h"

EnemyPlane::EnemyPlane(): m_pEnemy(new QPixmap(ENEMY_PLANE_PATH))
{
    //加载敌机资源
    //m_enemy.load(ENEMY_PLANE_PATH);

    //初始化敌机的坐标
    m_X = 0;
    m_Y = 0;

    //敌机的状态
    m_Free = true;

    //敌机的速度
    m_Speed = ENEMY_SPEED;

    //敌机矩形边框（用于检测碰撞）
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
    //判断敌机是否是空闲状态
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

