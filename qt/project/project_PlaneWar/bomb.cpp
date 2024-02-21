#include "bomb.h"

Bomb::Bomb()
{
    //初始化爆炸图片数组
    int i = 0;
    QString str;
    for(i = 1; i <= BOMB_MAX; ++i)
    {
        // ":res/res/bomb-%1.png"
        //做字符串拼接
        str = QString(BOMB_PATH).arg(i);
        m_pixArr.push_back(QPixmap(str));
    }

    //初始化坐标
    m_X = 0;
    m_Y = 0;

    //初始化空闲状态
    m_Free = true;

    //当前播放图片的下标
    m_Index = 0;

    //爆炸间隔记录
    m_Recoder = 0;
}

void Bomb::updateInfo()
{
    //空闲状态
    if(m_Free)
    {
        return;
    }

    m_Recoder++;

    if(m_Recoder < BOMB_INTERVAL) //记录爆炸间隔未到，不需要切图
    {
        return;
    }
    //重置记录
    m_Recoder = 0;

    //切换爆炸播放图片
    m_Index++;
    if(m_Index > BOMB_MAX - 1)
    {
        m_Index = 0;
        m_Free = true;
    }
}
