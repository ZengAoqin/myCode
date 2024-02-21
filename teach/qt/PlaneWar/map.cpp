#include "map.h"

Map::Map()
{
    //���ص�ͼ��Դ
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //����y�������
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    //���ó�ʼ��ͼ�������ٶ�
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    //�����һ��ͼƬ
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >= 0)
    {
        m_map1_posY = -GAME_HEIGHT;
    }

    //����ڶ���ͼƬ
    m_map2_posY += m_scroll_speed;
    if(m_map2_posY >= GAME_HEIGHT)
    {
        m_map2_posY = 0;
    }
}
