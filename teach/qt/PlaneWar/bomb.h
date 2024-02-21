#ifndef BOMB_H
#define BOMB_H
#include <QVector>
#include <QPixmap>
#include "config.h"

//���屬ը��
class Bomb
{
public:
    Bomb();

    void updateInfo();          //���±�ը��Ϣ(����ͼƬ�±꣬���ż��)
public:
    //�ű�ը��Դ����
    QVector<QPixmap> m_pixArr;

    //��ը������
    int m_X;
    int m_Y;

    //��ը״̬
    bool m_Free;

    //��ը��ͼ��ʱ����
    int m_Recoder;

    //��ըʱ���ص�ͼƬ�±�
    int m_Index;
};

#endif // BOMB_H
