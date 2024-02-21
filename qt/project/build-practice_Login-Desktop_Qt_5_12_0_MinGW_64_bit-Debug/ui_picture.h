/********************************************************************************
** Form generated from reading UI file 'picture.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_H
#define UI_PICTURE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Picture
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton_prev;
    QPushButton *pushButton_next;
    QPushButton *pushButton_start;
    QPushButton *pushButton_open;
    QPushButton *pushButton_stop;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Picture)
    {
        if (Picture->objectName().isEmpty())
            Picture->setObjectName(QString::fromUtf8("Picture"));
        Picture->resize(1090, 729);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/dog_head.png"), QSize(), QIcon::Normal, QIcon::Off);
        Picture->setWindowIcon(icon);
        centralWidget = new QWidget(Picture);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 1071, 621));
        label->setScaledContents(true);
        pushButton_prev = new QPushButton(centralWidget);
        pushButton_prev->setObjectName(QString::fromUtf8("pushButton_prev"));
        pushButton_prev->setGeometry(QRect(30, 650, 181, 51));
        pushButton_prev->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(230, 207, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(165, 255, 218);\n"
"}"));
        pushButton_next = new QPushButton(centralWidget);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setGeometry(QRect(870, 650, 181, 51));
        pushButton_next->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(230, 207, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(165, 255, 218);\n"
"}"));
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(240, 650, 181, 51));
        pushButton_start->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(230, 207, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(165, 255, 218);\n"
"}"));
        pushButton_open = new QPushButton(centralWidget);
        pushButton_open->setObjectName(QString::fromUtf8("pushButton_open"));
        pushButton_open->setGeometry(QRect(450, 650, 181, 51));
        pushButton_open->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(230, 207, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(165, 255, 218);\n"
"}"));
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(660, 650, 181, 51));
        pushButton_stop->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgb(230, 207, 255);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgb(165, 255, 218);\n"
"}"));
        Picture->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Picture);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Picture->setStatusBar(statusBar);

        retranslateUi(Picture);

        QMetaObject::connectSlotsByName(Picture);
    } // setupUi

    void retranslateUi(QMainWindow *Picture)
    {
        Picture->setWindowTitle(QApplication::translate("Picture", "\345\233\276\347\211\207\346\222\255\346\224\276\345\231\250", nullptr));
        label->setText(QString());
        pushButton_prev->setText(QApplication::translate("Picture", "\344\270\212\344\270\200\345\274\240", nullptr));
        pushButton_next->setText(QApplication::translate("Picture", "\344\270\213\344\270\200\345\274\240", nullptr));
        pushButton_start->setText(QApplication::translate("Picture", "\345\274\200\345\247\213\346\222\255\346\224\276", nullptr));
        pushButton_open->setText(QApplication::translate("Picture", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        pushButton_stop->setText(QApplication::translate("Picture", "\345\201\234\346\255\242\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Picture: public Ui_Picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_H
