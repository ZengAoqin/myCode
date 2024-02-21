/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionaction;
    QAction *actionsave;
    QAction *actionsaveas;
    QAction *actionquit;
    QAction *actionfont;
    QAction *actioncolor;
    QAction *actionhelp;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_E;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/dog_head.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionaction = new QAction(MainWindow);
        actionaction->setObjectName(QString::fromUtf8("actionaction"));
        actionaction->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionaction->setIcon(icon1);
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QString::fromUtf8("actionsave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionsave->setIcon(icon2);
        actionsaveas = new QAction(MainWindow);
        actionsaveas->setObjectName(QString::fromUtf8("actionsaveas"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/ssave.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionsaveas->setIcon(icon3);
        actionquit = new QAction(MainWindow);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/quit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionquit->setIcon(icon4);
        actionfont = new QAction(MainWindow);
        actionfont->setObjectName(QString::fromUtf8("actionfont"));
        actioncolor = new QAction(MainWindow);
        actioncolor->setObjectName(QString::fromUtf8("actioncolor"));
        actionhelp = new QAction(MainWindow);
        actionhelp->setObjectName(QString::fromUtf8("actionhelp"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionhelp->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1000, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu->addAction(actionaction);
        menu->addAction(actionsave);
        menu->addAction(actionsaveas);
        menu->addAction(actionquit);
        menu_E->addAction(actionfont);
        menu_E->addAction(actioncolor);
        menu_H->addAction(actionhelp);
        toolBar->addAction(actionaction);
        toolBar->addAction(actionsave);
        toolBar->addAction(actionsaveas);
        toolBar->addAction(actionquit);
        toolBar->addAction(actionhelp);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\256\260\344\272\213\346\234\254", nullptr));
        actionaction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#ifndef QT_NO_TOOLTIP
        actionaction->setToolTip(QApplication::translate("MainWindow", "open", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionaction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionsave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_SHORTCUT
        actionsave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionsaveas->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionsaveas->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionquit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actionfont->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\255\227\344\275\223", nullptr));
        actioncolor->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\351\242\234\350\211\262", nullptr));
        actionhelp->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(F)", nullptr));
        menu_E->setTitle(QApplication::translate("MainWindow", "\347\274\226\350\276\221(E)", nullptr));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(H)", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
