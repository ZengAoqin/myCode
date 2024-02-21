#include "easycloud.h"
#include "ui_easycloud.h"


EasyCloud::EasyCloud(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EasyCloud)
{
    ui->setupUi(this);
    m_player = new QMediaPlayer;
    m_playList = new QMediaPlaylist;
    m_vector = new QVector<Song>;
    m_timer = new QTimer;

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);   //去掉标题栏 任务栏图标最小化
    initTableWidget();                      //初始化播放列表
    initSearchTableWidget();                //初始化搜索结果列表
    m_count = 0;                            //初始化歌曲总数
    m_timer->setInterval(1000);             //设置定时器超时时间


    //绑定播放器状态改变信号和状态改变槽函数
    connect(m_player, &QMediaPlayer::stateChanged, this, &EasyCloud::onMediaStateChanged);

    //绑定定时器和更新时间及滑动条槽函数
    connect(m_timer, &QTimer::timeout, this, &EasyCloud::updateCurrentTime);

    //绑定媒体播放状态信号和槽函数
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &EasyCloud::onMediaStatusChanged);

//    QString musicPath = QCoreApplication::applicationDirPath() + "/music/song.mp3";
//    m_player->setMedia(QUrl::fromLocalFile(musicPath));
//    m_player->play();
}

EasyCloud::~EasyCloud()
{
    delete ui;
    delete m_player;
    delete m_playList;
    delete m_vector;
    delete m_timer;
}

//设置用户名
void EasyCloud::setUserName(QString userName)
{
    ui->labelUserName->setText("欢迎！" + userName);
}

//初始化播放列表
void EasyCloud::initTableWidget()
{
    ui->tableWidgetPlayList->setColumnCount(4);                                                             //设置列数
    ui->tableWidgetPlayList->setShowGrid(false);                                                            //去除网格
    ui->tableWidgetPlayList->setFrameShape(QFrame::NoFrame);                                                //去除边框
    ui->tableWidgetPlayList->setEditTriggers(QAbstractItemView::NoEditTriggers);                            //不可编辑
    ui->tableWidgetPlayList->setFocusPolicy(Qt::NoFocus);                                                   //不聚焦
    ui->tableWidgetPlayList->setSelectionBehavior(QTableWidget::SelectRows);                                //行选择
    ui->tableWidgetPlayList->setAlternatingRowColors(true);                                                 //背景色交替
    ui->tableWidgetPlayList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                          //隐藏横向滚动条

    ui->tableWidgetPlayList->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);     //水平表头文字
    ui->tableWidgetPlayList->horizontalHeader()->setHighlightSections(false);                               //水平表头取消焦点
    ui->tableWidgetPlayList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);                  //固定水平表头
    ui->tableWidgetPlayList->horizontalHeader()->setStyleSheet("QHeaderView::section {border:none;background-color:white}");
    ui->tableWidgetPlayList->horizontalHeader()->resizeSection(0, 50);
    ui->tableWidgetPlayList->horizontalHeader()->resizeSection(1, 400);
    ui->tableWidgetPlayList->horizontalHeader()->resizeSection(2, 200);
    ui->tableWidgetPlayList->horizontalHeader()->resizeSection(3, 100);

    ui->tableWidgetPlayList->verticalHeader()->setVisible(false);                                           //垂直表头不可见

    QTableWidgetItem* musicNum = new QTableWidgetItem;
    QTableWidgetItem* musicTitle = new QTableWidgetItem;
    QTableWidgetItem* musicArtist = new QTableWidgetItem;
    QTableWidgetItem* musicSize = new QTableWidgetItem;

    musicNum->setText("");
    musicTitle->setText(" 音乐标题");
    musicArtist->setText(" 歌手");
    musicSize->setText(" 大小");

    //设置横向表头内容
    ui->tableWidgetPlayList->setHorizontalHeaderItem(0, musicNum);
    ui->tableWidgetPlayList->setHorizontalHeaderItem(1, musicTitle);
    ui->tableWidgetPlayList->setHorizontalHeaderItem(2, musicArtist);
    ui->tableWidgetPlayList->setHorizontalHeaderItem(3, musicSize);
}

//初始化搜索列表
void EasyCloud::initSearchTableWidget()
{
    ui->tableWidgetSearchList->setColumnCount(4);                                                             //设置列数
    ui->tableWidgetSearchList->setShowGrid(false);                                                            //去除网格
    ui->tableWidgetSearchList->setFrameShape(QFrame::NoFrame);                                                //去除边框
    ui->tableWidgetSearchList->setEditTriggers(QAbstractItemView::NoEditTriggers);                            //不可编辑
    ui->tableWidgetSearchList->setFocusPolicy(Qt::NoFocus);                                                   //不聚焦
    ui->tableWidgetSearchList->setSelectionBehavior(QTableWidget::SelectRows);                                //行选择
    ui->tableWidgetSearchList->setAlternatingRowColors(true);                                                 //背景色交替

    ui->tableWidgetSearchList->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);     //水平表头文字
    ui->tableWidgetSearchList->horizontalHeader()->setHighlightSections(false);                               //水平表头取消焦点
    ui->tableWidgetSearchList->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);                  //固定水平表头
    ui->tableWidgetSearchList->horizontalHeader()->setStyleSheet("QHeaderView::section {border:none;background-color:white}");
    ui->tableWidgetSearchList->horizontalHeader()->resizeSection(0, 50);
    ui->tableWidgetSearchList->horizontalHeader()->resizeSection(1, 400);
    ui->tableWidgetSearchList->horizontalHeader()->resizeSection(2, 200);
    ui->tableWidgetSearchList->horizontalHeader()->resizeSection(3, 100);

    ui->tableWidgetSearchList->verticalHeader()->setVisible(false);                                           //垂直表头不可见

    QTableWidgetItem* musicNum = new QTableWidgetItem;
    QTableWidgetItem* musicTitle = new QTableWidgetItem;
    QTableWidgetItem* musicArtist = new QTableWidgetItem;
    QTableWidgetItem* musicId = new QTableWidgetItem;

    musicNum->setText("");
    musicTitle->setText(" 音乐标题");
    musicArtist->setText(" 歌手");
    musicId->setText(" 歌曲编号");

    //设置横向表头内容
    ui->tableWidgetSearchList->setHorizontalHeaderItem(0, musicNum);
    ui->tableWidgetSearchList->setHorizontalHeaderItem(1, musicTitle);
    ui->tableWidgetSearchList->setHorizontalHeaderItem(2, musicArtist);
    ui->tableWidgetSearchList->setHorizontalHeaderItem(3, musicId);
}

//跳转发现音乐界面
void EasyCloud::on_pushButtonDiscoverMusic_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    //设置按钮样式
    QFont font = ui->pushButtonDiscoverMusic->font();
    font.setPointSize(14);
    font.setBold(true);
    ui->pushButtonDiscoverMusic->setFont(font);

    //其他按钮还原
    font.setPointSize(11);
    font.setBold(false);
    ui->pushButtonPlayList->setFont(font);
    ui->pushButtonSearchMusic->setFont(font);
    ui->pushButtonOnlineMusic->setFont(font);
}

//跳转播放列表界面
void EasyCloud::on_pushButtonPlayList_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    //设置按钮样式
    QFont font = ui->pushButtonPlayList->font();
    font.setPointSize(14);
    font.setBold(true);
    ui->pushButtonPlayList->setFont(font);

    //其他按钮还原
    font.setPointSize(11);
    font.setBold(false);
    ui->pushButtonDiscoverMusic->setFont(font);
    ui->pushButtonSearchMusic->setFont(font);
    ui->pushButtonOnlineMusic->setFont(font);
}

//跳转搜索音乐界面
void EasyCloud::on_pushButtonSearchMusic_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    //设置按钮样式
    QFont font = ui->pushButtonSearchMusic->font();
    font.setPointSize(14);
    font.setBold(true);
    ui->pushButtonSearchMusic->setFont(font);

    //其他按钮还原
    font.setPointSize(11);
    font.setBold(false);
    ui->pushButtonDiscoverMusic->setFont(font);
    ui->pushButtonPlayList->setFont(font);
    ui->pushButtonOnlineMusic->setFont(font);
}

//跳转在线音乐界面
void EasyCloud::on_pushButtonOnlineMusic_clicked()
{
//    ui->stackedWidget->setCurrentIndex(3);

    //设置按钮样式
    QFont font = ui->pushButtonOnlineMusic->font();
    font.setPointSize(14);
    font.setBold(true);
    ui->pushButtonOnlineMusic->setFont(font);

    //其他按钮还原
    font.setPointSize(11);
    font.setBold(false);
    ui->pushButtonDiscoverMusic->setFont(font);
    ui->pushButtonPlayList->setFont(font);
    ui->pushButtonSearchMusic->setFont(font);
}

//点击导航栏关闭窗口
void EasyCloud::on_pushButtonClose_clicked()
{
    this->close();
}

//点击导航栏最小化窗口
void EasyCloud::on_pushButtonMin_clicked()
{
    setWindowState(Qt::WindowMinimized);
}

//点击导航栏最大化窗口
void EasyCloud::on_pushButtonMax_clicked()
{
//    setWindowState(Qt::WindowMaximized);
}

//实现鼠标拖拽移动
void EasyCloud::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPos();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

//鼠标移动事件
void EasyCloud::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bDrag)
    {	//这里if语句判断，让鼠标在特定控件上进行拖动才有效，比如自绘标题栏控件
        if(!ui->labelTitleBar->underMouse()){
            return;
        }
        //获得鼠标移动的距离
        QPoint distance = event->globalPos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

//鼠标释放事件
void EasyCloud::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

//触发键盘事件
void EasyCloud::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Return:                    //回车键
        {
            on_pushButtonSearchMusic_clicked();
            searchOnlineMusic();                //搜索网络歌曲
            break;
        }
        default:
        {
            break;
        }
    }
}

//点击随机播放按钮
void EasyCloud::on_pushButtonRandom_clicked()
{
    MyHttp http(nullptr);                       //实例化MyTttp对象
    QJsonObject jsonObj;
    QString url = "https://dataiqs.com/api/netease/music/?type=random";

    //http请求获取jsonObj
    bool requestState = http.getHttpJsonObject(url, jsonObj);
    qDebug() << "HTTP requestState:" << requestState;

    //如果状态为true
    if(requestState == true)
    {
        QJsonObject dataObj = jsonObj["data"].toObject();
        QString songUrl = dataObj["song_url"].toString();
        qDebug() << "songUrl:" << songUrl;

        //设置播放地址 播放
        m_player->setMedia(QUrl::fromLocalFile(songUrl));
        m_player->play();

        //设置播放按钮图片
        QIcon icon(":/img/img/play.png");
        ui->pushButtonPlay->setIcon(icon);
        ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));

        ui->labelSongName->setText("网络歌曲");
        ui->labelArtist->setText("未知歌手");
    }
}

//点击添加本地音乐按钮
void EasyCloud::on_pushButtonAddLocalMusic_clicked()
{
    QString filter = "*.mp3 *.wav *.wma";
    QStringList musicPaths = QFileDialog::getOpenFileNames(this, "选择音乐", "", filter);

    int i, rowNum;
    int pathsNum = musicPaths.count();
    QTableWidgetItem* item;

    if(pathsNum == 0)
    {
        return;
    }

    for(QString musicPath : musicPaths)
    {
        qDebug() << musicPath;
    }

    for(i = 0; i < pathsNum; ++i)
    {
        //将音频地址添加到播放列表
        m_playList->addMedia(QUrl::fromLocalFile(musicPaths[i]));

        //获取文件名
        QFileInfo info(musicPaths[i]);
        QString musicName = info.fileName();
        musicName.chop(4);          //删除后缀

        QString size = QString::number(info.size() / 1024 / 1024.00, 'f', 1) + "M";     //歌曲长度

        rowNum = m_count + i;       //当前行数
        ui->tableWidgetPlayList->insertRow(rowNum);                 //播放列表最下插入一行      

        //添加行数据
        item = new QTableWidgetItem(QString::number(rowNum + 1));
        ui->tableWidgetPlayList->setItem(rowNum, 0, item);

        item = new QTableWidgetItem(musicName);
        ui->tableWidgetPlayList->setItem(rowNum, 1, item);

        item = new QTableWidgetItem("未知歌手");
        ui->tableWidgetPlayList->setItem(rowNum, 2, item);

        item = new QTableWidgetItem(size);
        ui->tableWidgetPlayList->setItem(rowNum, 3, item);

        //加入vector容器
        Song song;
        song.setLocalSongInfo(rowNum, musicName, "未知歌手");
        m_vector->push_back(song);
    }

    m_count += pathsNum;            //将新加入的歌曲数量加入到总数
}

//点击列表开始播放按钮
void EasyCloud::on_pushButtonListPlay_clicked()
{
    if(!m_playList->isEmpty())
    {
        m_index = 0;

        //从第一首开始播放
        m_player->setMedia(m_playList);
        m_player->play();

        //设置歌曲名和歌手
        QString name, artist;
        Song song = m_vector->at(m_index);
        song.getLocalSongNameAndArtist(name, artist);

        ui->labelSongName->setText(name);
        ui->labelArtist->setText(artist);

        //设置播放按钮图片
        QIcon icon(":/img/img/play.png");
        ui->pushButtonPlay->setIcon(icon);
        ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));
    }
    else
    {
        qWarning() << "播放列表为空";
    }
}

//点击上一首按钮
void EasyCloud::on_pushButtonLastSong_clicked()
{
    //若播放器状态为停止 则返回
    if(m_player->state() == QMediaPlayer::StoppedState || m_player->playlist() == nullptr)
    {
        return;
    }

    //若歌曲索引为第一首歌 将索引设置为最后一首歌
    if(m_playList->currentIndex() == 0)
    {
        m_playList->setCurrentIndex(m_count - 1);
        m_index = m_count - 1;
    }
    //将播放歌曲索引设置为上一首歌
    else
    {
        int previousIndex = m_playList->previousIndex();
        m_playList->setCurrentIndex(previousIndex);
        m_index--;
    }

    m_player->play();

    //设置歌曲名和歌手
    QString name, artist;
    Song song = m_vector->at(m_index);
    song.getLocalSongNameAndArtist(name, artist);

    ui->labelSongName->setText(name);
    ui->labelArtist->setText(artist);
}

//点击下一首按钮
void EasyCloud::on_pushButtonNextSong_clicked()
{
    //若播放器状态为停止 则返回
    if(m_player->state() == QMediaPlayer::StoppedState || m_player->playlist() == nullptr)
    {
        return;
    }

    //若歌曲索引为最后一首歌 将索引设置为第一首歌
    if(m_playList->currentIndex() == m_count - 1)
    {
        m_playList->setCurrentIndex(0);
        m_index = 0;
    }
    //将播放歌曲索引设置为下一首歌
    else
    {
        int nextIndex = m_playList->nextIndex();
        m_playList->setCurrentIndex(nextIndex);
        m_index++;
    }

    m_player->play();

    //设置歌曲名和歌手
    QString name, artist;
    Song song = m_vector->at(m_index);
    song.getLocalSongNameAndArtist(name, artist);

    ui->labelSongName->setText(name);
    ui->labelArtist->setText(artist);
}

//点击播放暂停按钮
void EasyCloud::on_pushButtonPlay_clicked()
{
    //若播放器状态为停止 则返回
    if(m_player->state() == QMediaPlayer::StoppedState)
    {
        return;
    }

    //若播放器状态为播放 则暂停播放
    if(m_player->state() == QMediaPlayer::PlayingState)
    {
        m_player->pause();
        //设置停止按钮图片
        QIcon icon(":/img/img/stop.png");
        ui->pushButtonPlay->setIcon(icon);
        ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));
    }
    //若播放器状态为暂停 则继续播放
    else if (m_player->state() == QMediaPlayer::PausedState)
    {
        m_player->play();
        //设置播放按钮图片
        QIcon icon(":/img/img/play.png");
        ui->pushButtonPlay->setIcon(icon);
        ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));
    }
}

//双击列表行播放
void EasyCloud::on_tableWidgetPlayList_itemDoubleClicked(QTableWidgetItem *item)
{
    //获取当前行
    int index = item->row();

    m_player->setMedia(m_playList);
    m_playList->setCurrentIndex(index);         //设置索引
    m_index = index;

    m_player->play();

    //设置歌曲名和歌手
    QString name, artist;
    Song song = m_vector->at(m_index);
    song.getLocalSongNameAndArtist(name, artist);

    ui->labelSongName->setText(name);
    ui->labelArtist->setText(artist);

    //设置播放按钮图片
    QIcon icon(":/img/img/play.png");
    ui->pushButtonPlay->setIcon(icon);
    ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));
}

//播放状态改变槽函数
void EasyCloud::onMediaStateChanged(QMediaPlayer::State state)
{
    //若播放器状态为播放
    if(state == QMediaPlayer::PlayingState)
    {
        m_timer->start();
    }
    //若播放器状态为暂停
    else if (state == QMediaPlayer::PausedState)
    {
        m_timer->stop();
    }
}

//更新音乐时间及滑动条
void EasyCloud::updateCurrentTime()
{
    qint64 currentPosition = m_player->position();                          //获取当前进度（单位为毫秒）
    qint64 duration = m_player->duration();                                 //获取音频时长（单位为毫秒）

    qint64 seconds = (currentPosition / 1000) % 60;                         //获取当前进度总秒数
    qint64 minutes = (currentPosition / 1000) / 60;                         //获取当前进度总分钟数
    qint64 durationSeconds = (duration / 1000) % 60;                            //获取歌曲总秒数
    qint64 durationMinutes = (duration / 1000) / 60;                            //获取歌曲总分钟数

    QString currentDuration = QString::number(minutes) + ":" + QString::number(seconds);
    QString songDuration = QString::number(durationMinutes) + ":" + QString::number(durationSeconds);

    ui->labelCurrentTime->setText(currentDuration);
    ui->labelTime->setText(songDuration);

    int sliderMinimum = ui->horizontalSlider->minimum();                    //滑块的最小值
    int sliderMaximum = ui->horizontalSlider->maximum();                    //滑块的最大值

    //计算滑动条位置
    int sliderPosition = static_cast<int>((currentPosition / (duration * 1.00)) * (sliderMaximum - sliderMinimum));
//    qDebug() << sliderPosition;
    ui->horizontalSlider->setValue(sliderPosition);
}

//媒体播放状态改变槽函数 自动播放下一首
void EasyCloud::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    //若当前播放类型为playlist
    if (m_player->playlist() != nullptr) {

        //若playlist中歌曲数目大于一且歌曲播放结束
        if (m_count > 1 && status == QMediaPlayer::EndOfMedia)
        {
            //若歌曲索引为最后一首歌 将索引设置为第一首歌
            if(m_index == m_count - 1)
            {
                m_playList->setCurrentIndex(0);
                m_index = 0;
            }
            //将播放歌曲索引设置为下一首歌
            else
            {
                int nextIndex = m_playList->nextIndex();
                m_playList->setCurrentIndex(nextIndex);
                m_index++;
            }

            m_player->play();

            //设置歌曲名和歌手
            QString name, artist;
            Song song = m_vector->at(m_index);
            song.getLocalSongNameAndArtist(name, artist);

            ui->labelSongName->setText(name);
            ui->labelArtist->setText(artist);
        }
    }
}

//滑动条拖动释放
void EasyCloud::on_horizontalSlider_sliderReleased()
{
    int releasedValue = ui->horizontalSlider->value();
    int sliderMinimum = ui->horizontalSlider->minimum();                    //滑块的最小值
    int sliderMaximum = ui->horizontalSlider->maximum();                    //滑块的最大值
    qint64 duration = m_player->duration();                                 //获取音频时长（单位为毫秒）

    qint64 changedPosition = static_cast<qint64>(releasedValue * 1.00 / (sliderMaximum - sliderMinimum) * duration);    //计算改变后歌曲进度
    m_player->setPosition(changedPosition);                                 //设置改变后歌曲进度
}

//搜索网络歌曲
void EasyCloud::searchOnlineMusic()
{
    QString searchText = ui->lineEdit->text();
    if(searchText == "")
    {
        return;
    }

    MyHttp http(nullptr);                       //实例化MyTttp对象
    int i, id;
    QJsonObject jsonObj, itemObj;
    QTableWidgetItem* item;
    QString musicName, artist;

    //拼接搜索URL
    QString url = QString("https://dataiqs.com/api/netease/music/?type=song&msg=%1").arg(searchText);
    ui->labelSearchContent->setText(searchText);

    //http请求获取jsonObj
    bool requestState = http.getHttpJsonObject(url, jsonObj);
    qDebug() << "HTTP requestState:" << requestState;

    //清空表格内容并重置行数
    ui->tableWidgetSearchList->clearContents();
    ui->tableWidgetSearchList->setRowCount(0);

    //如果状态为true
    if(requestState == true)
    {
        QJsonArray dataArr = jsonObj["data"].toArray();

        for(i = 0; i < dataArr.size(); ++i)
        {
            itemObj = dataArr[i].toObject();
            id = itemObj["id"].toInt();
            musicName = itemObj["name"].toString();
            artist = itemObj["singername"].toString();

            //添加行数据
            ui->tableWidgetSearchList->insertRow(i);                 //播放列表最下插入一行

            item = new QTableWidgetItem(QString::number(i + 1));
            ui->tableWidgetSearchList->setItem(i, 0, item);

            item = new QTableWidgetItem(musicName);
            ui->tableWidgetSearchList->setItem(i, 1, item);

            item = new QTableWidgetItem(artist);
            ui->tableWidgetSearchList->setItem(i, 2, item);

            item = new QTableWidgetItem(QString::number(id));
            ui->tableWidgetSearchList->setItem(i, 3, item);
        }
    }
}

//双击搜索列表行播放
void EasyCloud::on_tableWidgetSearchList_itemDoubleClicked(QTableWidgetItem *item)
{
    //获取当前行
    int index = item->row();
    QString id = ui->tableWidgetSearchList->item(index, 3)->text();                                     //获取歌曲编号
    QString url = QString("https://dataiqs.com/api/netease/music/?type=songid&id=%1").arg(id);          //拼接url

    QTableWidgetItem *listItem;
    MyHttp http(nullptr);                       //实例化MyTttp对象
    QJsonObject jsonObj;

    //http请求获取jsonObj
    bool requestState = http.getHttpJsonObject(url, jsonObj);
    qDebug() << "HTTP requestState:" << requestState;

    if(requestState == true)
    {
        QString songUrl = jsonObj["song_url"].toString();

        //设置播放地址 播放
        m_player->setMedia(QUrl::fromLocalFile(songUrl));
        m_player->play();

        //设置歌曲名和歌手
        QString musicName = ui->tableWidgetSearchList->item(index, 1)->text();
        QString artist = ui->tableWidgetSearchList->item(index, 2)->text();

        ui->labelSongName->setText(musicName);
        ui->labelArtist->setText(artist);

        //设置播放按钮图片
        QIcon icon(":/img/img/play.png");
        ui->pushButtonPlay->setIcon(icon);
        ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));

        //将音频地址添加到播放列表
        m_playList->addMedia(QUrl::fromLocalFile(songUrl));
        ui->tableWidgetPlayList->insertRow(m_count);                 //播放列表最下插入一行

        //添加行数据
        listItem = new QTableWidgetItem(QString::number(m_count + 1));
        ui->tableWidgetPlayList->setItem(m_count, 0, listItem);

        listItem = new QTableWidgetItem(musicName);
        ui->tableWidgetPlayList->setItem(m_count, 1, listItem);

        listItem = new QTableWidgetItem(artist);
        ui->tableWidgetPlayList->setItem(m_count, 2, listItem);

        listItem = new QTableWidgetItem("");
        ui->tableWidgetPlayList->setItem(m_count, 3, listItem);

        //加入vector容器
        Song song;
        song.setLocalSongInfo(m_count, musicName, artist);
        m_vector->push_back(song);

        m_count++;
    }
}

//点击搜索列表开始播放
void EasyCloud::on_pushButtonPlaySearchMusic_clicked()
{
    QString id = ui->tableWidgetSearchList->item(0, 3)->text();                                     //获取歌曲编号
    QString url = QString("https://dataiqs.com/api/netease/music/?type=songid&id=%1").arg(id);          //拼接url

    QTableWidgetItem *listItem;
    MyHttp http(nullptr);                       //实例化MyTttp对象
    QJsonObject jsonObj;

    //http请求获取jsonObj
    bool requestState = http.getHttpJsonObject(url, jsonObj);
    qDebug() << "HTTP requestState:" << requestState;

    if(requestState == true)
    {
        QString songUrl = jsonObj["song_url"].toString();

        //设置播放地址 播放
        m_player->setMedia(QUrl::fromLocalFile(songUrl));
        m_player->play();

        //设置歌曲名和歌手
        QString musicName = ui->tableWidgetSearchList->item(0, 1)->text();
        QString artist = ui->tableWidgetSearchList->item(0, 2)->text();

        ui->labelSongName->setText(musicName);
        ui->labelArtist->setText(artist);

        //设置播放按钮图片
        QIcon icon(":/img/img/play.png");
        ui->pushButtonPlay->setIcon(icon);
        ui->pushButtonPlay->setIconSize(icon.actualSize(QSize(50, 45)));

        //将音频地址添加到播放列表
        m_playList->addMedia(QUrl::fromLocalFile(songUrl));
        ui->tableWidgetPlayList->insertRow(m_count);                 //播放列表最下插入一行

        //添加行数据
        listItem = new QTableWidgetItem(QString::number(m_count + 1));
        ui->tableWidgetPlayList->setItem(m_count, 0, listItem);

        listItem = new QTableWidgetItem(musicName);
        ui->tableWidgetPlayList->setItem(m_count, 1, listItem);

        listItem = new QTableWidgetItem(artist);
        ui->tableWidgetPlayList->setItem(m_count, 2, listItem);

        listItem = new QTableWidgetItem("");
        ui->tableWidgetPlayList->setItem(m_count, 3, listItem);

        //加入vector容器
        Song song;
        song.setLocalSongInfo(m_count, musicName, artist);
        m_vector->push_back(song);

        m_count++;
    }
}
