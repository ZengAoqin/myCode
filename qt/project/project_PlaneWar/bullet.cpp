#include "bullet.h"

Bullet::Bullet()
{
    //加载子弹的资源
    m_Bullet.load(BULLET_PATH);

    //子弹坐标的初始化
    m_X = 0;
    m_Y = 0;

    //子弹的状态
    m_Free = true;

    //子弹的速度
    m_Speed = BULLET_SPEED;

    //子弹矩形边框（用于检测碰撞）
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X, m_Y);
}

void Bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要计算坐标
    if(m_Free)
    {
        return;
    }

    //子弹向上移动
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if(m_Y <= -m_Bullet.height())
    {
        m_Free = true;
    }
}
