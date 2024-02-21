#ifndef LISTUSER_H
#define LISTUSER_H

#include <QMainWindow>
#include <QPushButton>      //按钮
#include <QListWidgetItem>  //列表条目
#include <QDebug>
#include <QMessageBox>
#include "form.h"
#include <QStringList>
#include <QStringListModel>

namespace Ui
{
class ListUser;
}

class ListUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListUser(QWidget* parent = nullptr);
    ~ListUser();

private slots:
    void on_btnString_clicked();

    void on_btnButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);

    void on_btnWindown_clicked();

    void on_btnStringView_clicked();

private:
    Ui::ListUser* ui;
};

#endif // LISTUSER_H
