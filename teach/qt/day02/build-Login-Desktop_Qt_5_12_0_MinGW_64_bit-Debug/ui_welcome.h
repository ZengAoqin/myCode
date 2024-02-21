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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcome
{
public:
    QLabel *label;
    QLabel *label_text;
    QPushButton *pushButton;

    void setupUi(QWidget *welcome)
    {
        if (welcome->objectName().isEmpty())
            welcome->setObjectName(QString::fromUtf8("welcome"));
        welcome->resize(585, 382);
        label = new QLabel(welcome);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 30, 271, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(34);
        font.setBold(true);
        font.setWeight(75);
        font.setKerning(true);
        label->setFont(font);
        label_text = new QLabel(welcome);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        label_text->setGeometry(QRect(90, 120, 271, 81));
        label_text->setFont(font);
        label_text->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255)"));
        pushButton = new QPushButton(welcome);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 260, 191, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(40);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255)"));
        pushButton->setAutoRepeatInterval(100);

        retranslateUi(welcome);

        QMetaObject::connectSlotsByName(welcome);
    } // setupUi

    void retranslateUi(QWidget *welcome)
    {
        welcome->setWindowTitle(QApplication::translate("welcome", "Form", nullptr));
        label->setText(QApplication::translate("welcome", "\346\210\221\346\230\257\344\270\273\347\225\214\351\235\242", nullptr));
        label_text->setText(QString());
        pushButton->setText(QApplication::translate("welcome", "LED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcome: public Ui_welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
