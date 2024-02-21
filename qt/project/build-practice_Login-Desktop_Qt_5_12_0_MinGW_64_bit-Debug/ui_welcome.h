/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->resize(1920, 1080);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/dog_head.png"), QSize(), QIcon::Normal, QIcon::Off);
        Welcome->setWindowIcon(icon);
        Welcome->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(Welcome);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1080));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/1.jpg")));
        label->setScaledContents(true);
        pushButton = new QPushButton(Welcome);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 310, 281, 71));
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
        layoutWidget = new QWidget(Welcome);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 80, 871, 111));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(35);
        label_4->setFont(font1);

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);

        horizontalLayout->addWidget(label_2);

        label_5 = new QLabel(Welcome);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 220, 1341, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(13);
        label_5->setFont(font2);
        pushButton_7 = new QPushButton(Welcome);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(110, 430, 281, 71));
        pushButton_7->setFont(font);
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        pushButton_8 = new QPushButton(Welcome);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(110, 550, 281, 71));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        pushButton_9 = new QPushButton(Welcome);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(110, 670, 281, 71));
        pushButton_9->setFont(font);
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "\344\270\273\347\225\214\351\235\242", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Welcome", "\350\256\241\347\256\227\345\231\250", nullptr));
        label_4->setText(QApplication::translate("Welcome", "\347\224\250\346\210\267\357\274\232", nullptr));
        label_3->setText(QString());
        label_2->setText(QApplication::translate("Welcome", "\346\254\242\350\277\216\346\235\245\345\210\260\344\270\273\347\225\214\351\235\242", nullptr));
        label_5->setText(QString());
        pushButton_7->setText(QApplication::translate("Welcome", "\350\256\260\344\272\213\346\234\254", nullptr));
        pushButton_8->setText(QApplication::translate("Welcome", "\350\256\241\346\227\266\345\231\250", nullptr));
        pushButton_9->setText(QApplication::translate("Welcome", "\345\233\276\347\211\207\346\222\255\346\224\276\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
