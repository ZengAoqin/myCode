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
    QLabel *label_image;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_PWD;
    QLabel *label_BG;
    QPushButton *pBtn_login;
    QPushButton *pBtn_cannel;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(660, 450);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"border:2px solid#ff0000;\n"
"border-radius:25px;\n"
"}\n"
"QLabel#label\n"
"{\n"
"COlor:red;\n"
"margin:10px;\n"
"padding:10px;\n"
"}\n"
"QLabel#label_image\n"
"{\n"
"border:2px solid#ff0000; \n"
"border-radius:60px;\n"
"border-image: url(:/image/1.jpg);\n"
"}\n"
"QPushButton\n"
"{\n"
"border:2px solid#ff0000;\n"
"border-radius:20px;\n"
"}\n"
"QPushButton:hover#pBtn_login\n"
"{\n"
"background-color:red\n"
"}\n"
"QPushButton:pressed#pBtn_login\n"
"{\n"
"background-color:rgb(0,255,0)\n"
"}\n"
"QPushButton:hover#pBtn_cannel\n"
"{\n"
"border-image: url(:/image/3.jpg);\n"
"}\n"
""));
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 20, 331, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(25);
        label->setFont(font);
        label_image = new QLabel(Login);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setGeometry(QRect(50, 10, 120, 120));
        label_image->setStyleSheet(QString::fromUtf8(""));
        lineEdit_Name = new QLineEdit(Login);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setGeometry(QRect(180, 150, 281, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(28);
        lineEdit_Name->setFont(font1);
        lineEdit_Name->setMaxLength(10);
        lineEdit_PWD = new QLineEdit(Login);
        lineEdit_PWD->setObjectName(QString::fromUtf8("lineEdit_PWD"));
        lineEdit_PWD->setGeometry(QRect(180, 220, 281, 51));
        lineEdit_PWD->setFont(font1);
        lineEdit_PWD->setMaxLength(10);
        lineEdit_PWD->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        label_BG = new QLabel(Login);
        label_BG->setObjectName(QString::fromUtf8("label_BG"));
        label_BG->setGeometry(QRect(0, 0, 650, 450));
        label_BG->setStyleSheet(QString::fromUtf8("border-image: url(:/image/2.jpg);"));
        pBtn_login = new QPushButton(Login);
        pBtn_login->setObjectName(QString::fromUtf8("pBtn_login"));
        pBtn_login->setGeometry(QRect(140, 360, 91, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(24);
        pBtn_login->setFont(font2);
        pBtn_cannel = new QPushButton(Login);
        pBtn_cannel->setObjectName(QString::fromUtf8("pBtn_cannel"));
        pBtn_cannel->setGeometry(QRect(350, 360, 91, 41));
        pBtn_cannel->setFont(font2);
        label_BG->raise();
        label->raise();
        label_image->raise();
        lineEdit_Name->raise();
        lineEdit_PWD->raise();
        pBtn_login->raise();
        pBtn_cannel->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        label->setText(QApplication::translate("Login", "XX\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        label_image->setText(QString());
        lineEdit_Name->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        lineEdit_PWD->setPlaceholderText(QApplication::translate("Login", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_BG->setText(QString());
        pBtn_login->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        pBtn_cannel->setText(QApplication::translate("Login", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
