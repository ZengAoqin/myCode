/********************************************************************************
** Form generated from reading UI file 'filerecvwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILERECVWINDOW_H
#define UI_FILERECVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileRecvWindow
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *FileRecvWindow)
    {
        if (FileRecvWindow->objectName().isEmpty())
            FileRecvWindow->setObjectName(QString::fromUtf8("FileRecvWindow"));
        FileRecvWindow->resize(810, 65);
        FileRecvWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));
        progressBar = new QProgressBar(FileRecvWindow);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 20, 801, 31));
        progressBar->setValue(0);

        retranslateUi(FileRecvWindow);

        QMetaObject::connectSlotsByName(FileRecvWindow);
    } // setupUi

    void retranslateUi(QWidget *FileRecvWindow)
    {
        FileRecvWindow->setWindowTitle(QApplication::translate("FileRecvWindow", "FileRecvWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileRecvWindow: public Ui_FileRecvWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILERECVWINDOW_H
