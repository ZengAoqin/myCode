#ifndef LISTUSER_H
#define LISTUSER_H

#include <QMainWindow>
#include <QListWidgetItem>


namespace Ui {
class ListUser;
}

class ListUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit ListUser(QWidget *parent = nullptr);
    ~ListUser();

private slots:
    void on_pb_string_clicked();

    void on_pb_button_clicked();

    void on_pb_lineEdit_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pb_widget_clicked();

    void on_pb_listString_clicked();

private:
    Ui::ListUser *ui;
};

#endif // LISTUSER_H
