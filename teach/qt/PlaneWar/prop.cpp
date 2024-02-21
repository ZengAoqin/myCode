#include "prop.h"

Prop::Prop(QObject* parent): QObject(parent)
{
    //加载道具的资源
    m_prop.load(PROP_PATH);

    //初始化坐标
    m_X = 0;
    m_Y = 0;

    //初始化空闲状态
    m_Free = true;

    //道具的移动速度
    m_Speed = 2;

    //道具矩形边框
    m_Rect.setWidth(m_prop.width());
    m_Rect.setHeight(m_prop.height());
    m_Rect.moveTo(m_X, m_Y);
}

int Prop::getType() const
{
    return m_Type;
}

void Prop::setType(int type)
{
    m_Type = type;
    if(type == 1) //加载速度道具的资源
    {
        m_prop.load(PROP_PATH);
    }
    else if(type == 2) //加载无敌道具的资源
    {
        m_prop.load(PROP_SUPER);
    }
}

void Prop::updatePosition()
{
    //空闲状态
    if(m_Free)
    {
        return ;
    }

    //道具是从上向下移动
    m_Y += m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if(m_Y >= GAME_HEIGHT)
    {
        m_Free = true;
        emit PropFree();
    }
}

int Prop::width() const
{
    return m_prop.width();
}

int Prop::height() const
{
    return m_prop.height();
}

void Prop::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X, m_Y);
}
