/********************************************************************************
** Form generated from reading UI file 'musicserver.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICSERVER_H
#define UI_MUSICSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MusicServer
{
public:
    QLabel *label;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonStart;
    QLabel *label_2;
    QLineEdit *lineEditTitle;
    QLineEdit *lineEditArtist;
    QPushButton *pushButtonFile;
    QPushButton *pushButtonAddMusic;
    QTableWidget *tableWidget;
    QTextEdit *textEdit;
    QPushButton *pushButtonDeleteMusic;
    QPushButton *pushButtonStop;

    void setupUi(QWidget *MusicServer)
    {
        if (MusicServer->objectName().isEmpty())
            MusicServer->setObjectName(QString::fromUtf8("MusicServer"));
        MusicServer->resize(1600, 900);
        label = new QLabel(MusicServer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1290, 50, 171, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(25);
        label->setFont(font);
        lineEditPort = new QLineEdit(MusicServer);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(1200, 120, 351, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(18);
        lineEditPort->setFont(font1);
        pushButtonStart = new QPushButton(MusicServer);
        pushButtonStart->setObjectName(QString::fromUtf8("pushButtonStart"));
        pushButtonStart->setGeometry(QRect(1300, 200, 151, 51));
        pushButtonStart->setFont(font1);
        label_2 = new QLabel(MusicServer);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1320, 330, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        label_2->setFont(font2);
        lineEditTitle = new QLineEdit(MusicServer);
        lineEditTitle->setObjectName(QString::fromUtf8("lineEditTitle"));
        lineEditTitle->setGeometry(QRect(1200, 400, 351, 51));
        lineEditTitle->setFont(font1);
        lineEditArtist = new QLineEdit(MusicServer);
        lineEditArtist->setObjectName(QString::fromUtf8("lineEditArtist"));
        lineEditArtist->setGeometry(QRect(1200, 480, 351, 51));
        lineEditArtist->setFont(font1);
        pushButtonFile = new QPushButton(MusicServer);
        pushButtonFile->setObjectName(QString::fromUtf8("pushButtonFile"));
        pushButtonFile->setGeometry(QRect(1200, 720, 151, 51));
        pushButtonFile->setFont(font1);
        pushButtonAddMusic = new QPushButton(MusicServer);
        pushButtonAddMusic->setObjectName(QString::fromUtf8("pushButtonAddMusic"));
        pushButtonAddMusic->setGeometry(QRect(1400, 720, 151, 51));
        pushButtonAddMusic->setFont(font1);
        tableWidget = new QTableWidget(MusicServer);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 1111, 841));
        textEdit = new QTextEdit(MusicServer);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(1200, 560, 351, 121));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        textEdit->setFont(font3);
        pushButtonDeleteMusic = new QPushButton(MusicServer);
        pushButtonDeleteMusic->setObjectName(QString::fromUtf8("pushButtonDeleteMusic"));
        pushButtonDeleteMusic->setGeometry(QRect(1400, 800, 151, 51));
        pushButtonDeleteMusic->setFont(font1);
        pushButtonStop = new QPushButton(MusicServer);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(1200, 800, 151, 51));
        pushButtonStop->setFont(font1);

        retranslateUi(MusicServer);

        QMetaObject::connectSlotsByName(MusicServer);
    } // setupUi

    void retranslateUi(QWidget *MusicServer)
    {
        MusicServer->setWindowTitle(QApplication::translate("MusicServer", "\351\237\263\344\271\220\346\234\215\345\212\241\345\231\250", nullptr));
        label->setText(QApplication::translate("MusicServer", "\351\237\263\344\271\220\346\234\215\345\212\241\345\231\250", nullptr));
        lineEditPort->setPlaceholderText(QApplication::translate("MusicServer", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267", nullptr));
        pushButtonStart->setText(QApplication::translate("MusicServer", "\345\220\257\345\212\250", nullptr));
        label_2->setText(QApplication::translate("MusicServer", "\346\267\273\345\212\240\351\237\263\344\271\220", nullptr));
        lineEditTitle->setPlaceholderText(QApplication::translate("MusicServer", "\351\237\263\344\271\220\346\240\207\351\242\230", nullptr));
        lineEditArtist->setText(QString());
        lineEditArtist->setPlaceholderText(QApplication::translate("MusicServer", "\346\255\214\346\211\213\345\220\215\347\247\260", nullptr));
        pushButtonFile->setText(QApplication::translate("MusicServer", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        pushButtonAddMusic->setText(QApplication::translate("MusicServer", "\346\267\273\345\212\240", nullptr));
        textEdit->setPlaceholderText(QString());
        pushButtonDeleteMusic->setText(QApplication::translate("MusicServer", "\345\210\240\351\231\244", nullptr));
        pushButtonStop->setText(QApplication::translate("MusicServer", "\345\201\234\346\255\242\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MusicServer: public Ui_MusicServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICSERVER_H
