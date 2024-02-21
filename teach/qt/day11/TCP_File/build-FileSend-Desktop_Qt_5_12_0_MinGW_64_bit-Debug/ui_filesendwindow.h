/********************************************************************************
** Form generated from reading UI file 'filesendwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESENDWINDOW_H
#define UI_FILESENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileSendWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineFile;
    QPushButton *btnFile;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineIP;
    QLineEdit *lineProt;
    QPushButton *btnConect;
    QProgressBar *progressBar;

    void setupUi(QWidget *FileSendWindow)
    {
        if (FileSendWindow->objectName().isEmpty())
            FileSendWindow->setObjectName(QString::fromUtf8("FileSendWindow"));
        FileSendWindow->resize(857, 297);
        layoutWidget = new QWidget(FileSendWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 821, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineFile = new QLineEdit(layoutWidget);
        lineFile->setObjectName(QString::fromUtf8("lineFile"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineFile->sizePolicy().hasHeightForWidth());
        lineFile->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        lineFile->setFont(font);

        horizontalLayout->addWidget(lineFile);

        btnFile = new QPushButton(layoutWidget);
        btnFile->setObjectName(QString::fromUtf8("btnFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnFile->sizePolicy().hasHeightForWidth());
        btnFile->setSizePolicy(sizePolicy1);
        btnFile->setMinimumSize(QSize(150, 0));
        btnFile->setMaximumSize(QSize(150, 16777215));
        QFont font1;
        font1.setPointSize(21);
        btnFile->setFont(font1);

        horizontalLayout->addWidget(btnFile);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineIP = new QLineEdit(layoutWidget);
        lineIP->setObjectName(QString::fromUtf8("lineIP"));
        sizePolicy.setHeightForWidth(lineIP->sizePolicy().hasHeightForWidth());
        lineIP->setSizePolicy(sizePolicy);
        lineIP->setFont(font);

        horizontalLayout_2->addWidget(lineIP);

        lineProt = new QLineEdit(layoutWidget);
        lineProt->setObjectName(QString::fromUtf8("lineProt"));
        sizePolicy.setHeightForWidth(lineProt->sizePolicy().hasHeightForWidth());
        lineProt->setSizePolicy(sizePolicy);
        lineProt->setFont(font);

        horizontalLayout_2->addWidget(lineProt);

        btnConect = new QPushButton(layoutWidget);
        btnConect->setObjectName(QString::fromUtf8("btnConect"));
        sizePolicy1.setHeightForWidth(btnConect->sizePolicy().hasHeightForWidth());
        btnConect->setSizePolicy(sizePolicy1);
        btnConect->setMinimumSize(QSize(150, 0));
        btnConect->setMaximumSize(QSize(150, 16777215));
        btnConect->setFont(font1);

        horizontalLayout_2->addWidget(btnConect);


        verticalLayout->addLayout(horizontalLayout_2);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setFont(font);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        retranslateUi(FileSendWindow);

        QMetaObject::connectSlotsByName(FileSendWindow);
    } // setupUi

    void retranslateUi(QWidget *FileSendWindow)
    {
        FileSendWindow->setWindowTitle(QApplication::translate("FileSendWindow", "FileSendWindow", nullptr));
        lineFile->setPlaceholderText(QApplication::translate("FileSendWindow", "\350\257\267\350\216\267\345\217\226\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
        btnFile->setText(QApplication::translate("FileSendWindow", "\346\265\217\350\247\210\346\226\207\344\273\266", nullptr));
        lineIP->setPlaceholderText(QApplication::translate("FileSendWindow", "\350\257\267\350\276\223\345\205\245IP\345\234\260\345\235\200", nullptr));
        lineProt->setPlaceholderText(QApplication::translate("FileSendWindow", "\350\257\267\350\276\223\345\205\245\347\253\257\345\217\243\345\217\267", nullptr));
        btnConect->setText(QApplication::translate("FileSendWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileSendWindow: public Ui_FileSendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESENDWINDOW_H
