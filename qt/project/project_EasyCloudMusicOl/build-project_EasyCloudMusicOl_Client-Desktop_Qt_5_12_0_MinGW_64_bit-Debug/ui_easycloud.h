/********************************************************************************
** Form generated from reading UI file 'easycloud.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASYCLOUD_H
#define UI_EASYCLOUD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasyCloud
{
public:
    QLabel *labelTitleBar;
    QLabel *labelIcon;
    QLabel *labelAppName;
    QPushButton *pushButtonMax;
    QPushButton *pushButtonClose;
    QPushButton *pushButtonMin;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *labelPage1;
    QLabel *labelCarousel;
    QLabel *labelRecommend;
    QPushButton *pushButtonRandom;
    QWidget *page_2;
    QLabel *labelPage2;
    QPushButton *pushButtonAddLocalMusic;
    QLabel *labelMyPlayList;
    QLabel *labelPlayListImg;
    QPushButton *pushButtonListPlay;
    QTableWidget *tableWidgetPlayList;
    QWidget *page_3;
    QLabel *labelPage3;
    QLabel *labelSearch;
    QLabel *labelSearchContent;
    QPushButton *pushButtonPlaySearchMusic;
    QTableWidget *tableWidgetSearchList;
    QWidget *page_4;
    QLabel *labelPage4;
    QLabel *labelRank;
    QLabel *labelrankimg;
    QTableWidget *tableWidgetRankingList;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonDiscoverMusic;
    QPushButton *pushButtonPlayList;
    QPushButton *pushButtonSearchMusic;
    QPushButton *pushButtonOnlineMusic;
    QLabel *labelSideBar;
    QLabel *labelPlayBar;
    QSlider *horizontalSlider;
    QPushButton *pushButtonLastSong;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonNextSong;
    QLabel *labelSongImg;
    QLabel *labelSongName;
    QLabel *labelArtist;
    QPushButton *pushButtonExpand;
    QLabel *labelCurrentTime;
    QLabel *labelTime;
    QLabel *labelUserName;
    QLineEdit *lineEdit;

    void setupUi(QWidget *EasyCloud)
    {
        if (EasyCloud->objectName().isEmpty())
            EasyCloud->setObjectName(QString::fromUtf8("EasyCloud"));
        EasyCloud->resize(1022, 670);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/window_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        EasyCloud->setWindowIcon(icon);
        labelTitleBar = new QLabel(EasyCloud);
        labelTitleBar->setObjectName(QString::fromUtf8("labelTitleBar"));
        labelTitleBar->setGeometry(QRect(0, 0, 1022, 60));
        labelTitleBar->setStyleSheet(QString::fromUtf8("background-color:rgb(236, 65, 65)"));
        labelIcon = new QLabel(EasyCloud);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setGeometry(QRect(16, 16, 30, 30));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bar_icon.png")));
        labelAppName = new QLabel(EasyCloud);
        labelAppName->setObjectName(QString::fromUtf8("labelAppName"));
        labelAppName->setGeometry(QRect(50, 18, 80, 25));
        labelAppName->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bar_font.png")));
        pushButtonMax = new QPushButton(EasyCloud);
        pushButtonMax->setObjectName(QString::fromUtf8("pushButtonMax"));
        pushButtonMax->setGeometry(QRect(944, 18, 31, 22));
        QFont font;
        font.setPointSize(18);
        pushButtonMax->setFont(font);
        pushButtonMax->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonMax\n"
"{\n"
"	background-color:rgb(235, 65, 65);\n"
"	color:rgb(255, 222, 244);\n"
"	border:0px\n"
"}\n"
"\n"
"QPushButton#pushButtonMax:hover\n"
"{\n"
"	background-color:rgb(235, 65, 65);\n"
"	color:white;\n"
"	border:0px\n"
"}"));
        pushButtonClose = new QPushButton(EasyCloud);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));
        pushButtonClose->setGeometry(QRect(980, 18, 31, 22));
        QFont font1;
        font1.setPointSize(20);
        pushButtonClose->setFont(font1);
        pushButtonClose->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonClose->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonClose\n"
"{\n"
"	background-color:rgb(235, 65, 65);\n"
"	color:rgb(255, 222, 244);\n"
"	border:0px\n"
"}\n"
"\n"
"QPushButton#pushButtonClose:hover\n"
"{\n"
"	background-color:rgb(235, 65, 65);\n"
"	color:white;\n"
"	border:0px\n"
"}"));
        pushButtonMin = new QPushButton(EasyCloud);
        pushButtonMin->setObjectName(QString::fromUtf8("pushButtonMin"));
        pushButtonMin->setGeometry(QRect(904, 20, 31, 20));
        QFont font2;
        font2.setPointSize(16);
        pushButtonMin->setFont(font2);
        pushButtonMin->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonMin->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonMin\n"
"{\n"
"	background-color:rgb(235, 65, 65);\n"
"	color:rgb(255, 222, 244);\n"
"	border:0px\n"
"}\n"
"\n"
"QPushButton#pushButtonMin:hover\n"
"{\n"
"	background-color:rgb(235, 65, 65);\n"
"	color:white;\n"
"	border:0px\n"
"}"));
        stackedWidget = new QStackedWidget(EasyCloud);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(200, 60, 821, 541));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        labelPage1 = new QLabel(page);
        labelPage1->setObjectName(QString::fromUtf8("labelPage1"));
        labelPage1->setGeometry(QRect(1, 0, 820, 540));
        labelPage1->setStyleSheet(QString::fromUtf8("background-color:white;"));
        labelCarousel = new QLabel(page);
        labelCarousel->setObjectName(QString::fromUtf8("labelCarousel"));
        labelCarousel->setGeometry(QRect(20, 10, 784, 250));
        labelCarousel->setPixmap(QPixmap(QString::fromUtf8(":/img/img/carousel.png")));
        labelRecommend = new QLabel(page);
        labelRecommend->setObjectName(QString::fromUtf8("labelRecommend"));
        labelRecommend->setGeometry(QRect(33, 260, 101, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        labelRecommend->setFont(font3);
        labelRecommend->setStyleSheet(QString::fromUtf8("color:black;"));
        pushButtonRandom = new QPushButton(page);
        pushButtonRandom->setObjectName(QString::fromUtf8("pushButtonRandom"));
        pushButtonRandom->setGeometry(QRect(23, 320, 780, 194));
        pushButtonRandom->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonRandom->setStyleSheet(QString::fromUtf8("background-image:url(:/img/img/random.png);\n"
"border:0px;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        labelPage2 = new QLabel(page_2);
        labelPage2->setObjectName(QString::fromUtf8("labelPage2"));
        labelPage2->setGeometry(QRect(1, 0, 820, 540));
        labelPage2->setStyleSheet(QString::fromUtf8("background-color:white;"));
        pushButtonAddLocalMusic = new QPushButton(page_2);
        pushButtonAddLocalMusic->setObjectName(QString::fromUtf8("pushButtonAddLocalMusic"));
        pushButtonAddLocalMusic->setGeometry(QRect(35, 120, 151, 36));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonAddLocalMusic->sizePolicy().hasHeightForWidth());
        pushButtonAddLocalMusic->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        pushButtonAddLocalMusic->setFont(font4);
        pushButtonAddLocalMusic->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAddLocalMusic->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonAddLocalMusic\n"
"{\n"
"	background-color:rgb(236, 65, 65);\n"
"	border:0px;\n"
"	border-radius:18px;\n"
"	color:white;\n"
"\n"
"}\n"
"\n"
"QPushButton#pushButtonAddLocalMusic:hover\n"
"{\n"
"	background-color:rgb(205, 50, 50);\n"
"	border:0px;\n"
"	border-radius:18px;\n"
"	color:white;\n"
"\n"
"}"));
        labelMyPlayList = new QLabel(page_2);
        labelMyPlayList->setObjectName(QString::fromUtf8("labelMyPlayList"));
        labelMyPlayList->setGeometry(QRect(140, 40, 191, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(20);
        labelMyPlayList->setFont(font5);
        labelMyPlayList->setStyleSheet(QString::fromUtf8("color:black;"));
        labelPlayListImg = new QLabel(page_2);
        labelPlayListImg->setObjectName(QString::fromUtf8("labelPlayListImg"));
        labelPlayListImg->setGeometry(QRect(30, 20, 93, 91));
        labelPlayListImg->setPixmap(QPixmap(QString::fromUtf8(":/img/img/playList.png")));
        pushButtonListPlay = new QPushButton(page_2);
        pushButtonListPlay->setObjectName(QString::fromUtf8("pushButtonListPlay"));
        pushButtonListPlay->setGeometry(QRect(210, 120, 121, 36));
        sizePolicy1.setHeightForWidth(pushButtonListPlay->sizePolicy().hasHeightForWidth());
        pushButtonListPlay->setSizePolicy(sizePolicy1);
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(13);
        font6.setBold(false);
        font6.setWeight(50);
        pushButtonListPlay->setFont(font6);
        pushButtonListPlay->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonListPlay->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonListPlay\n"
"{\n"
"	background-color:white;\n"
"	border:1px solid rgb(224,224,224);\n"
"	border-radius:18px;\n"
"	color:rgb(51, 51, 51);\n"
"\n"
"}\n"
"\n"
"QPushButton#pushButtonListPlay:hover\n"
"{\n"
"	background-color:rgb(246, 246, 247);\n"
"	border:1px solid rgb(224,224,224);\n"
"	border-radius:18px;\n"
"	color:rgb(51, 51, 51);\n"
"\n"
"}"));
        tableWidgetPlayList = new QTableWidget(page_2);
        tableWidgetPlayList->setObjectName(QString::fromUtf8("tableWidgetPlayList"));
        tableWidgetPlayList->setGeometry(QRect(35, 180, 761, 351));
        tableWidgetPlayList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        tableWidgetPlayList->setStyleSheet(QString::fromUtf8(""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        labelPage3 = new QLabel(page_3);
        labelPage3->setObjectName(QString::fromUtf8("labelPage3"));
        labelPage3->setGeometry(QRect(1, 0, 820, 540));
        labelPage3->setStyleSheet(QString::fromUtf8("background-color:white;"));
        labelSearch = new QLabel(page_3);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
        labelSearch->setGeometry(QRect(30, 30, 61, 41));
        QFont font7;
        font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font7.setPointSize(18);
        labelSearch->setFont(font7);
        labelSearch->setStyleSheet(QString::fromUtf8("color:black;"));
        labelSearchContent = new QLabel(page_3);
        labelSearchContent->setObjectName(QString::fromUtf8("labelSearchContent"));
        labelSearchContent->setGeometry(QRect(90, 30, 701, 41));
        labelSearchContent->setFont(font7);
        labelSearchContent->setStyleSheet(QString::fromUtf8("color:black;"));
        pushButtonPlaySearchMusic = new QPushButton(page_3);
        pushButtonPlaySearchMusic->setObjectName(QString::fromUtf8("pushButtonPlaySearchMusic"));
        pushButtonPlaySearchMusic->setGeometry(QRect(30, 90, 151, 36));
        sizePolicy1.setHeightForWidth(pushButtonPlaySearchMusic->sizePolicy().hasHeightForWidth());
        pushButtonPlaySearchMusic->setSizePolicy(sizePolicy1);
        pushButtonPlaySearchMusic->setFont(font4);
        pushButtonPlaySearchMusic->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonPlaySearchMusic->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonPlaySearchMusic\n"
"{\n"
"	background-color:rgb(236, 65, 65);\n"
"	border:0px;\n"
"	border-radius:18px;\n"
"	color:white;\n"
"\n"
"}\n"
"\n"
"QPushButton#pushButtonPlaySearchMusic:hover\n"
"{\n"
"	background-color:rgb(205, 50, 50);\n"
"	border:0px;\n"
"	border-radius:18px;\n"
"	color:white;\n"
"\n"
"}"));
        tableWidgetSearchList = new QTableWidget(page_3);
        tableWidgetSearchList->setObjectName(QString::fromUtf8("tableWidgetSearchList"));
        tableWidgetSearchList->setGeometry(QRect(30, 150, 761, 381));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        labelPage4 = new QLabel(page_4);
        labelPage4->setObjectName(QString::fromUtf8("labelPage4"));
        labelPage4->setGeometry(QRect(1, 0, 820, 540));
        labelPage4->setStyleSheet(QString::fromUtf8("background-color:white;"));
        labelRank = new QLabel(page_4);
        labelRank->setObjectName(QString::fromUtf8("labelRank"));
        labelRank->setGeometry(QRect(40, 30, 121, 51));
        QFont font8;
        font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font8.setPointSize(20);
        font8.setBold(true);
        font8.setWeight(75);
        labelRank->setFont(font8);
        labelRank->setStyleSheet(QString::fromUtf8("color:black;"));
        labelrankimg = new QLabel(page_4);
        labelrankimg->setObjectName(QString::fromUtf8("labelrankimg"));
        labelrankimg->setGeometry(QRect(30, 110, 185, 409));
        labelrankimg->setPixmap(QPixmap(QString::fromUtf8(":/img/img/ranking.png")));
        labelrankimg->setScaledContents(true);
        tableWidgetRankingList = new QTableWidget(page_4);
        tableWidgetRankingList->setObjectName(QString::fromUtf8("tableWidgetRankingList"));
        tableWidgetRankingList->setGeometry(QRect(240, 115, 561, 398));
        stackedWidget->addWidget(page_4);
        layoutWidget = new QWidget(EasyCloud);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 201, 181));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(15, 10, 10, 10);
        pushButtonDiscoverMusic = new QPushButton(layoutWidget);
        pushButtonDiscoverMusic->setObjectName(QString::fromUtf8("pushButtonDiscoverMusic"));
        sizePolicy1.setHeightForWidth(pushButtonDiscoverMusic->sizePolicy().hasHeightForWidth());
        pushButtonDiscoverMusic->setSizePolicy(sizePolicy1);
        QFont font9;
        font9.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font9.setPointSize(11);
        font9.setBold(false);
        font9.setItalic(false);
        font9.setWeight(50);
        pushButtonDiscoverMusic->setFont(font9);
        pushButtonDiscoverMusic->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDiscoverMusic->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonDiscoverMusic\n"
"{\n"
"	background-color:white;\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:rgb(51, 51, 51);\n"
"	text-align:left;\n"
"}\n"
"\n"
"QPushButton#pushButtonDiscoverMusic:hover\n"
"{\n"
"	background-color:rgb(246, 246, 247);\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:black;\n"
"	text-align:left;\n"
"}"));

        verticalLayout->addWidget(pushButtonDiscoverMusic);

        pushButtonPlayList = new QPushButton(layoutWidget);
        pushButtonPlayList->setObjectName(QString::fromUtf8("pushButtonPlayList"));
        sizePolicy1.setHeightForWidth(pushButtonPlayList->sizePolicy().hasHeightForWidth());
        pushButtonPlayList->setSizePolicy(sizePolicy1);
        QFont font10;
        font10.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font10.setPointSize(11);
        pushButtonPlayList->setFont(font10);
        pushButtonPlayList->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonPlayList->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonPlayList\n"
"{\n"
"	background-color:white;\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:rgb(51, 51, 51);\n"
"	text-align:left;\n"
"}\n"
"\n"
"QPushButton#pushButtonPlayList:hover\n"
"{\n"
"	background-color:rgb(246, 246, 247);\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:black;\n"
"	text-align:left;\n"
"}"));

        verticalLayout->addWidget(pushButtonPlayList);

        pushButtonSearchMusic = new QPushButton(layoutWidget);
        pushButtonSearchMusic->setObjectName(QString::fromUtf8("pushButtonSearchMusic"));
        sizePolicy1.setHeightForWidth(pushButtonSearchMusic->sizePolicy().hasHeightForWidth());
        pushButtonSearchMusic->setSizePolicy(sizePolicy1);
        pushButtonSearchMusic->setFont(font10);
        pushButtonSearchMusic->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonSearchMusic->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonSearchMusic\n"
"{\n"
"	background-color:white;\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:rgb(51, 51, 51);\n"
"	text-align:left;\n"
"}\n"
"\n"
"QPushButton#pushButtonSearchMusic:hover\n"
"{\n"
"	background-color:rgb(246, 246, 247);\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:black;\n"
"	text-align:left;\n"
"}"));

        verticalLayout->addWidget(pushButtonSearchMusic);

        pushButtonOnlineMusic = new QPushButton(layoutWidget);
        pushButtonOnlineMusic->setObjectName(QString::fromUtf8("pushButtonOnlineMusic"));
        sizePolicy1.setHeightForWidth(pushButtonOnlineMusic->sizePolicy().hasHeightForWidth());
        pushButtonOnlineMusic->setSizePolicy(sizePolicy1);
        pushButtonOnlineMusic->setFont(font10);
        pushButtonOnlineMusic->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonOnlineMusic->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonOnlineMusic\n"
"{\n"
"	background-color:white;\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:rgb(51, 51, 51);\n"
"	text-align:left;\n"
"}\n"
"\n"
"QPushButton#pushButtonOnlineMusic:hover\n"
"{\n"
"	background-color:rgb(246, 246, 247);\n"
"	border:0px;\n"
"	border-radius:5px;\n"
"	color:black;\n"
"	text-align:left;\n"
"}"));

        verticalLayout->addWidget(pushButtonOnlineMusic);

        labelSideBar = new QLabel(EasyCloud);
        labelSideBar->setObjectName(QString::fromUtf8("labelSideBar"));
        labelSideBar->setGeometry(QRect(0, 60, 201, 540));
        labelSideBar->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-right:1px solid rgb(224,224,224);"));
        labelPlayBar = new QLabel(EasyCloud);
        labelPlayBar->setObjectName(QString::fromUtf8("labelPlayBar"));
        labelPlayBar->setGeometry(QRect(0, 600, 1021, 70));
        labelPlayBar->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-top:1px solid rgb(224,224,224);"));
        horizontalSlider = new QSlider(EasyCloud);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(330, 650, 361, 16));
        horizontalSlider->setCursor(QCursor(Qt::ClosedHandCursor));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal \n"
"{\n"
"	background-color: rgb(236,65,65);\n"
"}"));
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButtonLastSong = new QPushButton(EasyCloud);
        pushButtonLastSong->setObjectName(QString::fromUtf8("pushButtonLastSong"));
        pushButtonLastSong->setGeometry(QRect(440, 615, 25, 25));
        pushButtonLastSong->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonLastSong->setStyleSheet(QString::fromUtf8("background-image:url(:/img/img/lastSong.png);\n"
"border:0px;"));
        pushButtonPlay = new QPushButton(EasyCloud);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(486, 605, 50, 45));
        pushButtonPlay->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonPlay->setStyleSheet(QString::fromUtf8("background-image:url(:/img/img/stop.png);\n"
"border:0px;"));
        pushButtonNextSong = new QPushButton(EasyCloud);
        pushButtonNextSong->setObjectName(QString::fromUtf8("pushButtonNextSong"));
        pushButtonNextSong->setGeometry(QRect(550, 615, 25, 25));
        pushButtonNextSong->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonNextSong->setStyleSheet(QString::fromUtf8("background-image:url(:/img/img/nextSong.png);\n"
"border:0px;"));
        labelSongImg = new QLabel(EasyCloud);
        labelSongImg->setObjectName(QString::fromUtf8("labelSongImg"));
        labelSongImg->setGeometry(QRect(20, 610, 50, 50));
        labelSongImg->setStyleSheet(QString::fromUtf8(""));
        labelSongImg->setPixmap(QPixmap(QString::fromUtf8(":/img/img/window_icon.jpg")));
        labelSongImg->setScaledContents(true);
        labelSongName = new QLabel(EasyCloud);
        labelSongName->setObjectName(QString::fromUtf8("labelSongName"));
        labelSongName->setGeometry(QRect(90, 610, 211, 21));
        QFont font11;
        font11.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font11.setPointSize(12);
        labelSongName->setFont(font11);
        labelSongName->setStyleSheet(QString::fromUtf8("color:black;"));
        labelArtist = new QLabel(EasyCloud);
        labelArtist->setObjectName(QString::fromUtf8("labelArtist"));
        labelArtist->setGeometry(QRect(90, 640, 161, 16));
        QFont font12;
        font12.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        labelArtist->setFont(font12);
        labelArtist->setStyleSheet(QString::fromUtf8("color:black;"));
        pushButtonExpand = new QPushButton(EasyCloud);
        pushButtonExpand->setObjectName(QString::fromUtf8("pushButtonExpand"));
        pushButtonExpand->setGeometry(QRect(930, 610, 59, 59));
        pushButtonExpand->setFont(font1);
        pushButtonExpand->setCursor(QCursor(Qt::ArrowCursor));
        pushButtonExpand->setStyleSheet(QString::fromUtf8("background-image:url(:/img/img/expand.png);\n"
"border:0px;"));
        labelCurrentTime = new QLabel(EasyCloud);
        labelCurrentTime->setObjectName(QString::fromUtf8("labelCurrentTime"));
        labelCurrentTime->setGeometry(QRect(280, 648, 41, 16));
        QFont font13;
        font13.setPointSize(10);
        labelCurrentTime->setFont(font13);
        labelCurrentTime->setStyleSheet(QString::fromUtf8("color:rgb(153,153,153);"));
        labelTime = new QLabel(EasyCloud);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(710, 648, 41, 16));
        labelTime->setFont(font13);
        labelTime->setStyleSheet(QString::fromUtf8("color:rgb(153,153,153);"));
        labelUserName = new QLabel(EasyCloud);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setGeometry(QRect(740, 15, 151, 31));
        QFont font14;
        font14.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font14.setPointSize(12);
        font14.setBold(false);
        font14.setWeight(50);
        labelUserName->setFont(font14);
        labelUserName->setLayoutDirection(Qt::LeftToRight);
        labelUserName->setStyleSheet(QString::fromUtf8("color:white;"));
        lineEdit = new QLineEdit(EasyCloud);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(230, 15, 241, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("border:0px;\n"
"border-radius:10px;"));
        lineEdit->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        labelSideBar->raise();
        labelTitleBar->raise();
        labelIcon->raise();
        labelAppName->raise();
        pushButtonMax->raise();
        pushButtonClose->raise();
        pushButtonMin->raise();
        stackedWidget->raise();
        layoutWidget->raise();
        labelPlayBar->raise();
        horizontalSlider->raise();
        pushButtonLastSong->raise();
        pushButtonPlay->raise();
        pushButtonNextSong->raise();
        labelSongImg->raise();
        labelSongName->raise();
        labelArtist->raise();
        pushButtonExpand->raise();
        labelCurrentTime->raise();
        labelTime->raise();
        labelUserName->raise();
        lineEdit->raise();

        retranslateUi(EasyCloud);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EasyCloud);
    } // setupUi

    void retranslateUi(QWidget *EasyCloud)
    {
        EasyCloud->setWindowTitle(QApplication::translate("EasyCloud", "EasyCloud", nullptr));
        labelTitleBar->setText(QString());
        labelIcon->setText(QString());
        labelAppName->setText(QString());
        pushButtonMax->setText(QApplication::translate("EasyCloud", "\342\226\241", nullptr));
        pushButtonClose->setText(QApplication::translate("EasyCloud", "\303\227", nullptr));
        pushButtonMin->setText(QApplication::translate("EasyCloud", "\342\200\224", nullptr));
        labelPage1->setText(QString());
        labelCarousel->setText(QString());
        labelRecommend->setText(QApplication::translate("EasyCloud", "\346\216\250\350\215\220\346\255\214\346\233\262 >", nullptr));
        pushButtonRandom->setText(QString());
        labelPage2->setText(QString());
        pushButtonAddLocalMusic->setText(QApplication::translate("EasyCloud", " \346\267\273\345\212\240\346\234\254\345\234\260\351\237\263\344\271\220", nullptr));
        labelMyPlayList->setText(QApplication::translate("EasyCloud", "\346\210\221\347\232\204\346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        labelPlayListImg->setText(QString());
        pushButtonListPlay->setText(QApplication::translate("EasyCloud", "\345\274\200\345\247\213\346\222\255\346\224\276", nullptr));
        labelPage3->setText(QString());
        labelSearch->setText(QApplication::translate("EasyCloud", "\346\220\234\347\264\242", nullptr));
        labelSearchContent->setText(QString());
        pushButtonPlaySearchMusic->setText(QApplication::translate("EasyCloud", "\345\274\200\345\247\213\346\222\255\346\224\276", nullptr));
        labelPage4->setText(QString());
        labelRank->setText(QApplication::translate("EasyCloud", "\345\256\230\346\226\271\346\246\234", nullptr));
        labelrankimg->setText(QString());
        pushButtonDiscoverMusic->setText(QApplication::translate("EasyCloud", " \345\217\221\347\216\260\351\237\263\344\271\220", nullptr));
        pushButtonPlayList->setText(QApplication::translate("EasyCloud", " \346\222\255\346\224\276\345\210\227\350\241\250", nullptr));
        pushButtonSearchMusic->setText(QApplication::translate("EasyCloud", " \346\220\234\347\264\242\351\237\263\344\271\220", nullptr));
        pushButtonOnlineMusic->setText(QApplication::translate("EasyCloud", " \345\256\230\346\226\271\346\246\234", nullptr));
        labelSideBar->setText(QString());
        labelPlayBar->setText(QString());
        pushButtonLastSong->setText(QString());
        pushButtonPlay->setText(QString());
        pushButtonNextSong->setText(QString());
        labelSongImg->setText(QString());
        labelSongName->setText(QString());
        labelArtist->setText(QString());
        pushButtonExpand->setText(QString());
        labelCurrentTime->setText(QApplication::translate("EasyCloud", "00:00", nullptr));
        labelTime->setText(QApplication::translate("EasyCloud", "00:00", nullptr));
        labelUserName->setText(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("EasyCloud", "\350\257\267\350\276\223\345\205\245\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EasyCloud: public Ui_EasyCloud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASYCLOUD_H
