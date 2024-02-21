#ifndef SONG_H
#define SONG_H

#include <QObject>
#include <QDebug>


class Song
{
//成员函数
public:
    Song(QString name, QString artist, QString addr);
    void getInfo();
    QString getName();
    QString getArtist();
    QString getAddr();

//成员变量
private:
    QString m_name;                         //歌曲名
    QString m_artist;                       //歌手
    QString m_addr;                         //歌曲文件地址
};

#endif // SONG_H
