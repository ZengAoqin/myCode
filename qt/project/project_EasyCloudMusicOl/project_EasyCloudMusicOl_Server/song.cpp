#include "song.h"


Song::Song(QString name, QString artist, QString addr)
{
    m_name = name;
    m_artist = artist;
    m_addr = addr;
}

void Song::getInfo()
{
    qDebug() << m_name << m_artist << m_addr;
}

QString Song::getName()
{
    return m_name;
}

QString Song::getArtist()
{
    return m_artist;
}

QString Song::getAddr()
{
    return m_addr;
}
