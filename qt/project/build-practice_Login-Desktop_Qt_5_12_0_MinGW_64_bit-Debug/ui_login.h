/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(1920, 1080);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        Login->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/dog_head.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setAutoFillBackground(false);
        Login->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"}\n"
"\n"
"QPushButton#pushButton\n"
"{\n"
"	border:2px solid black;\n"
"	border-radius:10px;\n"
"	background-color:white;\n"
"}\n"
"\n"
"QPushButton:hover#pushButton\n"
"{\n"
"	background-color:rgb(230, 207, 255);\n"
"}\n"
"\n"
"QPushButton:pressed#pushButton\n"
"{\n"
"	background-color:rgb(165, 255, 218);\n"
"}"));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(840, 140, 241, 131));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(35);
        label->setFont(font1);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 130, 171, 161));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/dog.png")));
        label_2->setScaledContents(true);
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        lineEdit = new QLineEdit(Login);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(790, 490, 321, 51));
        QFont font2;
        font2.setPointSize(20);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(Login);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(790, 570, 321, 51));
        lineEdit_2->setFont(font2);
        lineEdit_2->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(820, 700, 261, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        pushButton->setFont(font3);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 1920, 1080));
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3\n"
"{\n"
"	border-image:url(:/img/2.jpg);\n"
"}\n"
""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/img/2.jpg")));
        label_3->setScaledContents(true);
        label_3->raise();
        label->raise();
        label_2->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        pushButton->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("Login", "\346\254\242\350\277\216\347\231\273\345\275\225", nullptr));
        label_2->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        pushButton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
