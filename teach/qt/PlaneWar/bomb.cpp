#include "bomb.h"

Bomb::Bomb()
{
    //��ʼ����ըͼƬ����
    int i = 0;
    QString str;
    for(i = 1; i <= BOMB_MAX; ++i)
    {
        // ":res/res/bomb-%1.png"
        //���ַ���ƴ��
        str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //��ʼ������
    m_X = 0;
    m_Y = 0;

    //��ʼ������״̬
    m_Free = true;

    //��ǰ����ͼƬ���±�
    m_Index = 0;

    //��ը�����¼
    m_Recoder = 0;
}

void Bomb::updateInfo()
{
    //����״̬
    if(m_Free)
    {
        return;
    }

    m_Recoder++;

    if(m_Recoder < BOMB_INTERVAL) //��¼��ը���δ��������Ҫ��ͼ
    {
        return;
    }
    //���ü�¼
    m_Recoder = 0;

    //�л���ը����ͼƬ
    m_Index++;
    if(m_Index > BOMB_MAX - 1)
    {
        m_Index = 0;
        m_Free = true;
    }
}
