#ifndef EASYCLOUD_H
#define EASYCLOUD_H

#include <QWidget>
#include <QMouseEvent>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QMediaPlaylist>
#include <QTimer>

#include "config.h"
#include "myhttp.h"
#include "song.h"


namespace Ui {
class EasyCloud;
}

class EasyCloud : public QWidget
{
    Q_OBJECT

//成员函数
public:
    explicit EasyCloud(QWidget *parent = nullptr);
    ~EasyCloud();
    void setUserName(QString userName);
    void initTableWidget();
    void initSearchTableWidget();

private slots:
    void on_pushButtonDiscoverMusic_clicked();
    void on_pushButtonPlayList_clicked();
    void on_pushButtonSearchMusic_clicked();
    void on_pushButtonOnlineMusic_clicked();
    void on_pushButtonClose_clicked();
    void on_pushButtonMin_clicked();
    void on_pushButtonMax_clicked();
    void on_pushButtonRandom_clicked();
    void on_pushButtonAddLocalMusic_clicked();
    void on_pushButtonListPlay_clicked();
    void on_pushButtonLastSong_clicked();
    void on_pushButtonNextSong_clicked();
    void on_pushButtonPlay_clicked();
    void on_tableWidgetPlayList_itemDoubleClicked(QTableWidgetItem *item);
    void onMediaStateChanged(QMediaPlayer::State state);
    void updateCurrentTime();
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);
    void on_horizontalSlider_sliderReleased();
    void searchOnlineMusic();
    void on_tableWidgetSearchList_itemDoubleClicked(QTableWidgetItem *item);
    void on_pushButtonPlaySearchMusic_clicked();

protected:
    //鼠标拖动窗体移动
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //触发键盘事件
    void keyPressEvent(QKeyEvent* event);


//成员变量
protected:
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

private:
    Ui::EasyCloud *ui;    
    QString userName;
    QMediaPlayer* m_player;                                  //播放器
    int m_count;                                             //歌曲总数
    int m_index;                                             //当前播放歌曲索引
    QMediaPlaylist* m_playList;                              //播放列表
    QVector<Song>* m_vector;                                 //歌曲vector容器
    QTimer* m_timer;                                         //定时器
};

#endif // EASYCLOUD_H
