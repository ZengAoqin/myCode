/********************************************************************************
** Form generated from reading UI file 'timer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMER_H
#define UI_TIMER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Timer
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;

    void setupUi(QWidget *Timer)
    {
        if (Timer->objectName().isEmpty())
            Timer->setObjectName(QString::fromUtf8("Timer"));
        Timer->resize(1000, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/dog_head.png"), QSize(), QIcon::Normal, QIcon::Off);
        Timer->setWindowIcon(icon);
        label = new QLabel(Timer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1000, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/4.jpg")));
        label->setScaledContents(true);
        pushButton = new QPushButton(Timer);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 430, 261, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        pushButton_2 = new QPushButton(Timer);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 430, 261, 71));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        lcdNumber = new QLCDNumber(Timer);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(180, 20, 651, 71));
        lcdNumber->setDigitCount(19);
        lcdNumber_2 = new QLCDNumber(Timer);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(380, 100, 231, 131));
        lcdNumber_2->setDigitCount(3);

        retranslateUi(Timer);

        QMetaObject::connectSlotsByName(Timer);
    } // setupUi

    void retranslateUi(QWidget *Timer)
    {
        Timer->setWindowTitle(QApplication::translate("Timer", "\350\256\241\346\227\266\345\231\250", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Timer", "\345\274\200\345\247\213\350\256\241\346\227\266", nullptr));
        pushButton_2->setText(QApplication::translate("Timer", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Timer: public Ui_Timer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMER_H
