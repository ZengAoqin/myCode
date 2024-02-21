/********************************************************************************
** Form generated from reading UI file 'cloudlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOUDLOGIN_H
#define UI_CLOUDLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CloudLogin
{
public:
    QLabel *label;
    QPushButton *pushButtonLogin;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditUsername;
    QLineEdit *lineEditPassword;
    QLabel *label_2;
    QPushButton *pushButtonCloseWindow;
    QLabel *label_3;
    QCheckBox *checkBox;
    QLabel *label_4;

    void setupUi(QWidget *CloudLogin)
    {
        if (CloudLogin->objectName().isEmpty())
            CloudLogin->setObjectName(QString::fromUtf8("CloudLogin"));
        CloudLogin->resize(350, 530);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CloudLogin->sizePolicy().hasHeightForWidth());
        CloudLogin->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/window_icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        CloudLogin->setWindowIcon(icon);
        CloudLogin->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	border:1px solid rgb(217, 217, 217);\n"
"}\n"
"\n"
"border-radius:10px"));
        label = new QLabel(CloudLogin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 350, 530));
        label->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 255, 255)"));
        pushButtonLogin = new QPushButton(CloudLogin);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(50, 350, 241, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas-with-Yahei"));
        font.setPointSize(15);
        font.setBold(false);
        font.setWeight(50);
        pushButtonLogin->setFont(font);
        pushButtonLogin->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonLogin\n"
"{\n"
"	border:1px solid rgb(217, 217, 217);\n"
"	border-radius:5px;\n"
"	background-color:rgb(255, 58, 58);\n"
"	color:white;\n"
"}\n"
"\n"
"QPushButton#pushButtonLogin:hover\n"
"{\n"
"	border:1px solid rgb(217, 217, 217);\n"
"	border-radius:5px;\n"
"	background-color:rgb(229, 52, 52);\n"
"	color:white;\n"
"}"));
        layoutWidget = new QWidget(CloudLogin);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 230, 241, 91));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditUsername = new QLineEdit(layoutWidget);
        lineEditUsername->setObjectName(QString::fromUtf8("lineEditUsername"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditUsername->sizePolicy().hasHeightForWidth());
        lineEditUsername->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(11);
        lineEditUsername->setFont(font1);

        verticalLayout->addWidget(lineEditUsername);

        lineEditPassword = new QLineEdit(layoutWidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        sizePolicy1.setHeightForWidth(lineEditPassword->sizePolicy().hasHeightForWidth());
        lineEditPassword->setSizePolicy(sizePolicy1);
        lineEditPassword->setFont(font1);
        lineEditPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEditPassword);

        label_2 = new QLabel(CloudLogin);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 120, 69, 67));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/icon.png")));
        label_2->setScaledContents(true);
        pushButtonCloseWindow = new QPushButton(CloudLogin);
        pushButtonCloseWindow->setObjectName(QString::fromUtf8("pushButtonCloseWindow"));
        pushButtonCloseWindow->setGeometry(QRect(290, 10, 51, 41));
        QFont font2;
        font2.setPointSize(20);
        pushButtonCloseWindow->setFont(font2);
        pushButtonCloseWindow->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonCloseWindow\n"
"{\n"
"	background-color:white;\n"
"	border:0px;\n"
"	color:rgb(217, 217, 217);\n"
"}\n"
"\n"
"QPushButton#pushButtonCloseWindow:hover\n"
"{\n"
"	background-color:white;\n"
"	border:0px;\n"
"	color:black;\n"
"}"));
        label_3 = new QLabel(CloudLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 60, 141, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(25);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255, 58, 58);"));
        checkBox = new QCheckBox(CloudLogin);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 480, 291, 31));
        checkBox->setStyleSheet(QString::fromUtf8("color:black;"));
        label_4 = new QLabel(CloudLogin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 410, 260, 50));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/img/img/apps.png")));
        label_4->setScaledContents(true);

        retranslateUi(CloudLogin);

        QMetaObject::connectSlotsByName(CloudLogin);
    } // setupUi

    void retranslateUi(QWidget *CloudLogin)
    {
        CloudLogin->setWindowTitle(QApplication::translate("CloudLogin", "Form", nullptr));
        label->setText(QString());
        pushButtonLogin->setText(QApplication::translate("CloudLogin", "\347\231\273\345\275\225", nullptr));
        lineEditUsername->setPlaceholderText(QApplication::translate("CloudLogin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        lineEditPassword->setText(QString());
        lineEditPassword->setPlaceholderText(QApplication::translate("CloudLogin", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_2->setText(QString());
        pushButtonCloseWindow->setText(QApplication::translate("CloudLogin", "\303\227", nullptr));
        label_3->setText(QApplication::translate("CloudLogin", "\346\230\223\344\272\221\351\237\263\344\271\220", nullptr));
        checkBox->setText(QApplication::translate("CloudLogin", "\345\220\214\346\204\217 \343\200\212\346\234\215\345\212\241\346\235\241\346\254\276\343\200\213\343\200\212\351\232\220\347\247\201\346\224\277\347\255\226\343\200\213\343\200\212\345\204\277\347\253\245\344\277\235\346\212\244\346\235\241\346\254\276\343\200\213", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CloudLogin: public Ui_CloudLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOUDLOGIN_H
