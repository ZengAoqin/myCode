#ifndef JSONTEST_H
#define JSONTEST_H

#include <QWidget>
#include <QJsonObject>      //json对象
#include <QJsonArray>       //json数组
#include <QDebug>
#include <QJsonDocument>    //json格式文档
#include <QJsonParseError>  //json解析错误

namespace Ui
{
class JsonTest;
}

class JsonTest : public QWidget
{
    Q_OBJECT

public:
    explicit JsonTest(QWidget* parent = nullptr);
    ~JsonTest();

private slots:
    void on_btnJson_clicked();

private:
    Ui::JsonTest* ui;
};

#endif // JSONTEST_H
