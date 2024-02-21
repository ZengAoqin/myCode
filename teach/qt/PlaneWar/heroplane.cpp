#include "heroplane.h"

HeroPlane::HeroPlane()
{
    //���طɻ���ͼƬ
    m_Plane.load(HERO_PLANE_PATH);
    m_Invi.load(HERO_INVI_PATH);

    //��ʼ������
    m_X = GAME_WIDTH / 2 - m_Plane.width() / 2;
    m_Y = GAME_HEIGHT - m_Plane.height() - 100;

    //��ʼ���ٶ�
    m_Speed = HERO_SPEED;

    //���α߿� ��ײ���ʹ��
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X, m_Y);

    //��ʼ���ӵ��ļ����¼����
    m_recorder = 0;
}

void HeroPlane::shoot()
{
    //�ۼ��¼������¼����
    m_recorder++;

    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    //�����ӵ�
    int i = 0;
    for(i = 0; i < BULLET_NUM; ++i)
    {
        //����ӵ��ǿ���״̬���ӵ��������ӵ�
        if(m_bullet[i].m_Free)
        {
            m_bullet[i].m_Free = false;
            m_bullet[i].m_X = m_X + m_Plane.width() / 2 - 10;
            m_bullet[i].m_Y = m_Y - 25;
            break;
        }
    }
}

void HeroPlane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X, m_Y);
}

void HeroPlane::getPosition(int& x, int& y)
{
    x = m_X;
    y = m_Y;
}

int HeroPlane::width() const
{
    return m_Rect.width();
}

int HeroPlane::height() const
{
    return m_Rect.height();
}

void HeroPlane::setHeroSpeed(int speed)
{
    m_Speed = speed;
}

int HeroPlane::getHeroSpeed() const
{
    return m_Speed;
}
