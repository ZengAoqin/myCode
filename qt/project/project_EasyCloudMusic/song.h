#ifndef SONG_H
#define SONG_H

#include <QObject>

#include <config.h>


class Song
{
//成员函数
public:
    void setLocalSongInfo(int num, QString name, QString artist);
    void getLocalSongNameAndArtist(QString& name, QString& artist);

//成员变量
private:
    int m_num;                              //歌曲编号
    QString m_name;                         //歌曲名
    QString m_artist;                       //歌手
    QString m_addr;                         //歌曲文件地址
};

#endif // SONG_H
