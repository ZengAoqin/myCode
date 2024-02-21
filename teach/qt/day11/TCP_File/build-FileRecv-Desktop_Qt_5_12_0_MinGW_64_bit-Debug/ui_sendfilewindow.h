PushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(630, 150, 131, 61));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(50, 300, 251, 41));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(340, 300, 261, 41));
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(640, 290, 131, 61));
        SendFileWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SendFileWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 847, 26));
        SendFileWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SendFileWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SendFileWindow->setStatusBar(statusbar);

        retranslateUi(SendFileWindow);

        QMetaObject::connectSlotsByName(SendFileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SendFileWindow)
    {
        SendFileWindow->setWindowTitle(QCoreApplication::translate("SendFileWindow", "SendFileWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("SendFileWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SendFileWindow", "\345\217\221\351\200\201", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("SendFileWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendFileWindow: public Ui_SendFileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDFILEWINDOW_H
