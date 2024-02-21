#include "map.h"

Map::Map()
{
    //加载地图资源
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    //设置y轴的坐标
    m_map1_posY = -GAME_HEIGHT;
    m_map2_posY = 0;

    //设置初始地图滚动的速度
    m_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    //处理第一张图片
    m_map1_posY += m_scroll_speed;
    if(m_map1_posY >= 0)
    {
        m_map1_posY = -GAME_HEIGHT;
    }

    //处理第二张图片
    m_map2_posY += m_scroll_speed;
    if(m_map2_posY >= GAME_HEIGHT)
    {
        m_map2_posY = 0;
    }
}
