#ifndef MUSICSERVER_H
#define MUSICSERVER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QThread>

#include "song.h"


namespace Ui {
class MusicServer;
}

class MusicServer : public QWidget
{
    Q_OBJECT

public:
    explicit MusicServer(QWidget *parent = nullptr);
    ~MusicServer();

private slots:
    void on_pushButtonStart_clicked();
    void newClient();
    void recvData();
    void on_pushButtonFile_clicked();
    void on_pushButtonAddMusic_clicked();
    void on_pushButtonDeleteMusic_clicked();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_pushButtonStop_clicked();

private:
    void initTableWidget();
    void sendMusicList(QTcpSocket* socket);
    void sendMusic(QTcpSocket* socket, int musicIndex);
    void addMusic();

private:
    Ui::MusicServer *ui;
    QMediaPlayer* m_player;             //播放器
    int m_count;                        //歌曲总数
    QList<Song>* m_songList;            //歌曲链表
    QTcpServer* m_server;
    bool m_on;
};

#endif // MUSICSERVER_H
