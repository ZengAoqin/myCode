#include "fruit.h"

Fruit::Fruit()
{

}

//º”‘ÿ◊ ‘¥Õº∆¨
bool Fruit::loadResource(const QString& filename)
{
    return m_Res.load(filename);
}

void Fruit::setFreeStatus(bool bFree)
{
    m_Free = bFree;
}

bool Fruit::getFreeStatus()
{
    return m_Free;
}
