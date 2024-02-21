#include "bullet.h"

Bullet::Bullet()
{
    //�����ӵ�����Դ
    m_Bullet.load(BULLET_PATH);

    //�ӵ�����ĳ�ʼ��
    m_X = 0;
    m_Y = 0;

    //�ӵ���״̬
    m_Free = true;

    //�ӵ����ٶ�
    m_Speed = BULLET_SPEED;

    //�ӵ����α߿����ڼ����ײ��
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X, m_Y);
}

void Bullet::updatePosition()
{
    //����ӵ��ǿ���״̬������Ҫ��������
    if(m_Free)
    {
        return;
    }

    //�ӵ������ƶ�
    m_Y -= m_Speed;
    m_Rect.moveTo(m_X, m_Y);

    if(m_Y <= -m_Bullet.height())
    {
        m_Free = true;
    }
}
