/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pb_7;
    QPushButton *pb_8;
    QPushButton *pb_9;
    QPushButton *pb_add;
    QPushButton *pb_4;
    QPushButton *pb_5;
    QPushButton *pb_6;
    QPushButton *pb_min;
    QPushButton *pb_1;
    QPushButton *pb_2;
    QPushButton *pb_3;
    QPushButton *pb_mul;
    QPushButton *pb_clear;
    QPushButton *pb_0;
    QPushButton *pb_equal;
    QPushButton *pb_div;

    void setupUi(QWidget *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(1920, 1080);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/dog_head.png"), QSize(), QIcon::Normal, QIcon::Off);
        View->setWindowIcon(icon);
        View->setStyleSheet(QString::fromUtf8("QPushButton#pushButton\n"
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
        label = new QLabel(View);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1920, 1080));
        QFont font;
        font.setPointSize(6);
        label->setFont(font);
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/3.jpg")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(View);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 90, 251, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(35);
        label_2->setFont(font1);
        pushButton = new QPushButton(View);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 110, 281, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(20);
        pushButton->setFont(font2);
        lineEdit = new QLineEdit(View);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 220, 661, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(25);
        lineEdit->setFont(font3);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        layoutWidget = new QWidget(View);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 310, 661, 381));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pb_7 = new QPushButton(layoutWidget);
        pb_7->setObjectName(QString::fromUtf8("pb_7"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pb_7->sizePolicy().hasHeightForWidth());
        pb_7->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(20);
        pb_7->setFont(font4);

        gridLayout->addWidget(pb_7, 0, 0, 1, 1);

        pb_8 = new QPushButton(layoutWidget);
        pb_8->setObjectName(QString::fromUtf8("pb_8"));
        sizePolicy.setHeightForWidth(pb_8->sizePolicy().hasHeightForWidth());
        pb_8->setSizePolicy(sizePolicy);
        pb_8->setFont(font4);

        gridLayout->addWidget(pb_8, 0, 1, 1, 1);

        pb_9 = new QPushButton(layoutWidget);
        pb_9->setObjectName(QString::fromUtf8("pb_9"));
        sizePolicy.setHeightForWidth(pb_9->sizePolicy().hasHeightForWidth());
        pb_9->setSizePolicy(sizePolicy);
        pb_9->setFont(font4);

        gridLayout->addWidget(pb_9, 0, 2, 1, 1);

        pb_add = new QPushButton(layoutWidget);
        pb_add->setObjectName(QString::fromUtf8("pb_add"));
        sizePolicy.setHeightForWidth(pb_add->sizePolicy().hasHeightForWidth());
        pb_add->setSizePolicy(sizePolicy);
        pb_add->setFont(font4);

        gridLayout->addWidget(pb_add, 0, 3, 1, 1);

        pb_4 = new QPushButton(layoutWidget);
        pb_4->setObjectName(QString::fromUtf8("pb_4"));
        sizePolicy.setHeightForWidth(pb_4->sizePolicy().hasHeightForWidth());
        pb_4->setSizePolicy(sizePolicy);
        pb_4->setFont(font4);

        gridLayout->addWidget(pb_4, 1, 0, 1, 1);

        pb_5 = new QPushButton(layoutWidget);
        pb_5->setObjectName(QString::fromUtf8("pb_5"));
        sizePolicy.setHeightForWidth(pb_5->sizePolicy().hasHeightForWidth());
        pb_5->setSizePolicy(sizePolicy);
        pb_5->setFont(font4);

        gridLayout->addWidget(pb_5, 1, 1, 1, 1);

        pb_6 = new QPushButton(layoutWidget);
        pb_6->setObjectName(QString::fromUtf8("pb_6"));
        sizePolicy.setHeightForWidth(pb_6->sizePolicy().hasHeightForWidth());
        pb_6->setSizePolicy(sizePolicy);
        pb_6->setFont(font4);

        gridLayout->addWidget(pb_6, 1, 2, 1, 1);

        pb_min = new QPushButton(layoutWidget);
        pb_min->setObjectName(QString::fromUtf8("pb_min"));
        sizePolicy.setHeightForWidth(pb_min->sizePolicy().hasHeightForWidth());
        pb_min->setSizePolicy(sizePolicy);
        pb_min->setFont(font4);

        gridLayout->addWidget(pb_min, 1, 3, 1, 1);

        pb_1 = new QPushButton(layoutWidget);
        pb_1->setObjectName(QString::fromUtf8("pb_1"));
        sizePolicy.setHeightForWidth(pb_1->sizePolicy().hasHeightForWidth());
        pb_1->setSizePolicy(sizePolicy);
        pb_1->setFont(font4);

        gridLayout->addWidget(pb_1, 2, 0, 1, 1);

        pb_2 = new QPushButton(layoutWidget);
        pb_2->setObjectName(QString::fromUtf8("pb_2"));
        sizePolicy.setHeightForWidth(pb_2->sizePolicy().hasHeightForWidth());
        pb_2->setSizePolicy(sizePolicy);
        pb_2->setFont(font4);

        gridLayout->addWidget(pb_2, 2, 1, 1, 1);

        pb_3 = new QPushButton(layoutWidget);
        pb_3->setObjectName(QString::fromUtf8("pb_3"));
        sizePolicy.setHeightForWidth(pb_3->sizePolicy().hasHeightForWidth());
        pb_3->setSizePolicy(sizePolicy);
        pb_3->setFont(font4);

        gridLayout->addWidget(pb_3, 2, 2, 1, 1);

        pb_mul = new QPushButton(layoutWidget);
        pb_mul->setObjectName(QString::fromUtf8("pb_mul"));
        sizePolicy.setHeightForWidth(pb_mul->sizePolicy().hasHeightForWidth());
        pb_mul->setSizePolicy(sizePolicy);
        pb_mul->setFont(font4);

        gridLayout->addWidget(pb_mul, 2, 3, 1, 1);

        pb_clear = new QPushButton(layoutWidget);
        pb_clear->setObjectName(QString::fromUtf8("pb_clear"));
        sizePolicy.setHeightForWidth(pb_clear->sizePolicy().hasHeightForWidth());
        pb_clear->setSizePolicy(sizePolicy);
        pb_clear->setFont(font4);

        gridLayout->addWidget(pb_clear, 3, 0, 1, 1);

        pb_0 = new QPushButton(layoutWidget);
        pb_0->setObjectName(QString::fromUtf8("pb_0"));
        sizePolicy.setHeightForWidth(pb_0->sizePolicy().hasHeightForWidth());
        pb_0->setSizePolicy(sizePolicy);
        pb_0->setFont(font4);

        gridLayout->addWidget(pb_0, 3, 1, 1, 1);

        pb_equal = new QPushButton(layoutWidget);
        pb_equal->setObjectName(QString::fromUtf8("pb_equal"));
        sizePolicy.setHeightForWidth(pb_equal->sizePolicy().hasHeightForWidth());
        pb_equal->setSizePolicy(sizePolicy);
        pb_equal->setFont(font4);

        gridLayout->addWidget(pb_equal, 3, 2, 1, 1);

        pb_div = new QPushButton(layoutWidget);
        pb_div->setObjectName(QString::fromUtf8("pb_div"));
        sizePolicy.setHeightForWidth(pb_div->sizePolicy().hasHeightForWidth());
        pb_div->setSizePolicy(sizePolicy);
        pb_div->setFont(font4);

        gridLayout->addWidget(pb_div, 3, 3, 1, 1);


        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QWidget *View)
    {
        View->setWindowTitle(QApplication::translate("View", "\350\256\241\347\256\227\345\231\250", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("View", "\350\256\241\347\256\227\345\231\250", nullptr));
        pushButton->setText(QApplication::translate("View", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        lineEdit->setText(QString());
        pb_7->setText(QApplication::translate("View", "7", nullptr));
        pb_8->setText(QApplication::translate("View", "8", nullptr));
        pb_9->setText(QApplication::translate("View", "9", nullptr));
        pb_add->setText(QApplication::translate("View", "+", nullptr));
        pb_4->setText(QApplication::translate("View", "4", nullptr));
        pb_5->setText(QApplication::translate("View", "5", nullptr));
        pb_6->setText(QApplication::translate("View", "6", nullptr));
        pb_min->setText(QApplication::translate("View", "-", nullptr));
        pb_1->setText(QApplication::translate("View", "1", nullptr));
        pb_2->setText(QApplication::translate("View", "2", nullptr));
        pb_3->setText(QApplication::translate("View", "3", nullptr));
        pb_mul->setText(QApplication::translate("View", "*", nullptr));
        pb_clear->setText(QApplication::translate("View", "c", nullptr));
        pb_0->setText(QApplication::translate("View", "0", nullptr));
        pb_equal->setText(QApplication::translate("View", "=", nullptr));
        pb_div->setText(QApplication::translate("View", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
