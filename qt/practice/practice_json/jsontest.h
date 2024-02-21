#ifndef JSONTEST_H
#define JSONTEST_H

#include <QWidget>
#include <QJsonObject>              //json对象
#include <QJsonArray>               //json数组
#include <QJsonDocument>            //json文档
#include <QJsonParseError>          //json错误
#include <QDebug>
#include <QFileDialog>


namespace Ui {
class JsonTest;
}

class JsonTest : public QWidget
{
    Q_OBJECT

public:
    explicit JsonTest(QWidget *parent = nullptr);
    ~JsonTest();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::JsonTest *ui;
};

#endif // JSONTEST_H
