#ifndef MAP_H
#define MAP_H

#include <QPixmap>
#include "config.h"

//�����ͼ��
class Map
{
public:
    Map();      //���캯��

    void mapPosition();     //��ͼ�����������

    //��ͼ����ͼƬ
    QPixmap m_map1;     //ͼƬ1
    QPixmap m_map2;     //ͼƬ2

    //��ͼY������
    int m_map1_posY;    //ͼƬ1��y������
    int m_map2_posY;    //ͼƬ2��y������

    //��ͼ�Ĺ����ٶ�
    int m_scroll_speed;
};

#endif // MAP_H
