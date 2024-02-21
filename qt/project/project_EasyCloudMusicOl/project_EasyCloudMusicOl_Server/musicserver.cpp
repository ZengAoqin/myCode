#include "musicserver.h"
#include "ui_musicserver.h"

MusicServer::MusicServer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicServer)
{
    ui->setupUi(this);

    m_player = new QMediaPlayer;
    m_count = 0;
    m_songList = new QList<Song>;
    m_server = new QTcpServer;
    m_on = false;

    //绑定新连接进入的信号与客户端新连接槽函数
    connect(m_server, &QTcpServer::newConnection, this, &MusicServer::newClient);

    initTableWidget();
    addMusic();
}

MusicServer::~MusicServer()
{
    delete ui;
    delete m_songList;
    delete m_server;
    delete m_player;
}


//开启服务器
void MusicServer::on_pushButtonStart_clicked()
{
    //获取端口号
    QString port = ui->lineEditPort->text();

    //开启服务器
    if(!m_on)
    {
        m_on = true;
        m_server->listen(QHostAddress::Any, port.toUShort());           //监听客户端连接
        ui->pushButtonStart->setText("关闭");
        qDebug() << "服务器已开启";
    }
    //关闭服务器
    else
    {
        m_on = false;
        m_server->close();
        ui->pushButtonStart->setText("启动");
        qDebug() << "服务器已关闭";
    }
}

//客户端新连接槽函数
void MusicServer::newClient()
{
    //获取与客户端连接套接字
    QTcpSocket* socket = m_server->nextPendingConnection();

    //关联读取信号获取客户端数据
    connect(socket, &QTcpSocket::readyRead, this, &MusicServer::recvData);
}

//接收客户端数据槽函数
void MusicServer::recvData()
{
    //获取客户端套接字
    QTcpSocket* socket = dynamic_cast<QTcpSocket*>(sender());

    //获取客户端IP
    QString IP = socket->peerAddress().toString();
    IP.remove("::ffff:");

    //读取数据
    QByteArray byteArr = socket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);
    QJsonObject jsonObj = jsonDoc.object();
    QString requestType = jsonObj["requestType"].toString();

    qDebug() << "IP:" + IP + " requestType:" + requestType;

    //请求类型为musicList
    if(requestType == "musicList")
    {
        sendMusicList(socket);                              //向客户端发送MusicList
    }
    //请求类型为musicDownload
    else if(requestType == "musicDownload")
    {
        int musicIndex = jsonObj["musicIndex"].toInt();
        sendMusic(socket, musicIndex);                      //发送音乐文件
    }
}

//向客户端发送MusicList
void MusicServer::sendMusicList(QTcpSocket* socket)
{
    QJsonObject jsonObj, jsonItem;
    QJsonArray jsonArr;

    //迭代器遍历
    QList<Song>::iterator iter;
    for(iter = m_songList->begin(); iter != m_songList->end(); ++iter)
    {
        jsonItem["name"] = iter->getName();
        jsonItem["artist"] = iter->getArtist();
        jsonArr.append(jsonItem);
    }

    //数据类型为musicList
    jsonObj["dataType"] = "musicList";
    jsonObj["data"] = jsonArr;

    //将JSON数据转换为字节数组
    QJsonDocument jsonDoc(jsonObj);
    QByteArray byteArr = jsonDoc.toJson();

    //发送给客户端
    socket->write(byteArr);
}

//发送音乐文件
void MusicServer::sendMusic(QTcpSocket *socket, int musicIndex)
{
    qDebug() << "musicIndex:" << musicIndex;

    //获取文件信息
    Song song = m_songList->at(musicIndex);
    QString name = song.getName();
    QString artist = song.getArtist();
    QString path = song.getAddr();

    //创建文件对象
    QFile file(path);
    QFileInfo fileInfo(path);
    qint64 fileSize = fileInfo.size();

    bool ret = file.open(QIODevice::ReadOnly);                 //可读权限

    if(ret == true)
    {
        QJsonObject jsonObj;

        //循环发送文件数据
        while(!file.atEnd())
        {
            QByteArray blockData = file.read(1024 * 40);                                //从文件读取块数据
            QString block = QString::fromLocal8Bit(blockData.toBase64());               //将块数据转换为Base64字符串

            jsonObj["dataType"] = "musicDownload";                                      //数据类型为musicDownload
            jsonObj["name"] = name;
            jsonObj["artist"] = artist;
            jsonObj["size"] = fileSize;
            jsonObj["music"] = block;

            //将JSON数据转换为字节数组
            QJsonDocument jsonDoc(jsonObj);
            QByteArray byteArr = jsonDoc.toJson();

            //发送给客户端
            socket->write(byteArr);
            socket->waitForBytesWritten();                                               //等待数据发送完成
            QThread::msleep(1);
        }

        file.close();
    }
    else
    {
        qWarning() << "无法打开文件";
    }
}

//添加音乐路径
void MusicServer::on_pushButtonFile_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "选择文件", "", "*.mp3 *.wav *.wma");
    ui->textEdit->setText(path);
}

//添加音乐
void MusicServer::on_pushButtonAddMusic_clicked()
{
    int row = m_count;
    QString musicName = ui->lineEditTitle->text();
    QString artist = ui->lineEditArtist->text();
    QString path = ui->textEdit->toPlainText();

    QTableWidget* tableWidget = ui->tableWidget;
    tableWidget->insertRow(row);                            //播放列表最下插入一行

    //添加行数据
    QTableWidgetItem* item = new QTableWidgetItem(musicName);
    tableWidget->setItem(row, 0, item);

    item = new QTableWidgetItem(artist);
    tableWidget->setItem(row, 1, item);

    item = new QTableWidgetItem(path);
    tableWidget->setItem(row, 2, item);

    //加入链表
    Song song(musicName, artist, path);
    m_songList->append(song);

    m_count++;
}

//删除音乐
void MusicServer::on_pushButtonDeleteMusic_clicked()
{
    int row = ui->tableWidget->currentItem()->row();        //获取选中行
    QMessageBox::information(this, "提示", "确认删除第" + QString::number(row + 1) + "首歌曲?");
    ui->tableWidget->removeRow(row);                        //删除选中行
    m_songList->takeAt(row);                                //移除歌曲链表中的选中歌曲
    m_count--;

    //迭代器遍历
    QList<Song>::iterator iter;
    for(iter = m_songList->begin(); iter != m_songList->end(); ++iter)
    {
        iter->getInfo();
    }
}

//双击单曲播放
void MusicServer::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    //获取当前行
    int index = item->row();

    //获取播放路径
    Song song = m_songList->at(index);
    QString musicPath = song.getAddr();

    //播放音乐
    m_player->setMedia(QUrl::fromLocalFile(musicPath));
    m_player->play();
}

//停止播放
void MusicServer::on_pushButtonStop_clicked()
{
    m_player->stop();
}

//初始化列表
void MusicServer::initTableWidget()
{
    ui->tableWidget->setColumnCount(3);                                                             //设置列数
    ui->tableWidget->setShowGrid(false);                                                            //去除网格
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);                            //不可编辑
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);                                                   //不聚焦
    ui->tableWidget->setSelectionBehavior(QTableWidget::SelectRows);                                //行选择
    ui->tableWidget->setAlternatingRowColors(true);                                                 //背景色交替
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                          //隐藏横向滚动条

    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);     //水平表头文字
    ui->tableWidget->horizontalHeader()->setHighlightSections(false);                               //水平表头取消焦点
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);                  //固定水平表头
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {border:none;background-color:white}");
    ui->tableWidget->horizontalHeader()->resizeSection(0, 200);
    ui->tableWidget->horizontalHeader()->resizeSection(1, 100);
    ui->tableWidget->horizontalHeader()->resizeSection(2, 750);

    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);                  //固定水平表头

    QTableWidgetItem* musicTitle = new QTableWidgetItem;
    QTableWidgetItem* musicArtist = new QTableWidgetItem;
    QTableWidgetItem* musicPath = new QTableWidgetItem;

    musicTitle->setText(" 音乐标题");
    musicArtist->setText(" 歌手");
    musicPath->setText(" 路径");

    //设置横向表头内容
    ui->tableWidget->setHorizontalHeaderItem(0, musicTitle);
    ui->tableWidget->setHorizontalHeaderItem(1, musicArtist);
    ui->tableWidget->setHorizontalHeaderItem(2, musicPath);
}

//添加音乐
void MusicServer::addMusic()
{
    QTableWidget* tableWidget = ui->tableWidget;

    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    QTableWidgetItem* item = new QTableWidgetItem("手写的从前");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\手写的从前.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song1("手写的从前", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\手写的从前.mp3");
    m_songList->append(song1);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("爷爷泡的茶");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\爷爷泡的茶.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song2("爷爷泡的茶", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\爷爷泡的茶.mp3");
    m_songList->append(song2);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("晴天");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\晴天.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song3("晴天", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\晴天.mp3");
    m_songList->append(song3);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("等你下课");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\等你下课.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song4("等你下课", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\等你下课.mp3");
    m_songList->append(song4);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("断了的弦");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\断了的弦.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song5("断了的弦", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\断了的弦.mp3");
    m_songList->append(song5);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("发如雪");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\发如雪.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song6("发如雪", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\发如雪.mp3");
    m_songList->append(song6);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("游园会");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\游园会.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song7("游园会", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\游园会.mp3");
    m_songList->append(song7);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("不爱我就拉倒");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\不爱我就拉倒.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song8("不爱我就拉倒", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\不爱我就拉倒.mp3");
    m_songList->append(song8);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("暗号");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\暗号.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song9("暗号", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\暗号.mp3");
    m_songList->append(song9);

    m_count++;


    tableWidget->insertRow(m_count);                            //播放列表最下插入一行
    //添加行数据
    item = new QTableWidgetItem("听见下雨的声音");
    tableWidget->setItem(m_count, 0, item);

    item = new QTableWidgetItem("周杰伦");
    tableWidget->setItem(m_count, 1, item);

    item = new QTableWidgetItem("D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\听见下雨的声音.mp3");
    tableWidget->setItem(m_count, 2, item);

    //加入链表
    Song song10("听见下雨的声音", "周杰伦", "D:\\workspace\\code\\Linux Shared Space\\work\\qt\\project\\project_EasyCloudMusicOl\\test\\听见下雨的声音.mp3");
    m_songList->append(song10);

    m_count++;
}
