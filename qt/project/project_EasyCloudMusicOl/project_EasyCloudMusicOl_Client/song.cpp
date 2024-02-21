#include "song.h"


void Song::setLocalSongInfo(int num, QString name, QString artist)
{
    m_num = num;
    m_name = name;
    m_artist = artist;
}

void Song::getLocalSongNameAndArtist(QString &name, QString &artist)
{
    name = m_name;
    artist = m_artist;
}
