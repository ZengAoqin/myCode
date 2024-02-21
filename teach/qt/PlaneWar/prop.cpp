#include "prop.h"

Prop::Prop(QObject* parent): QObject(parent)
{
    //���ص��ߵ���Դ
    m_prop.load(PROP_PATH);

    //��ʼ������
    m_X = 0;
    m_Y = 0;

    //��ʼ������״̬
    m_Free = true;

    //���ߵ��ƶ��ٶ�
    m_Speed = 2;

    //���߾��α߿�
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
    if(type == 1) //�����ٶȵ��ߵ���Դ
    {
        m_prop.load(PROP_PATH);
    }
    else if(type == 2) //�����޵е��ߵ���Դ
    {
        m_prop.load(PROP_SUPER);
    }
}

void Prop::updatePosition()
{
    //����״̬
    if(m_Free)
    {
        return ;
    }

    //�����Ǵ��������ƶ�
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
