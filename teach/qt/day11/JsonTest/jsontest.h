#ifndef JSONTEST_H
#define JSONTEST_H

#include <QWidget>
#include <QJsonObject>      //json����
#include <QJsonArray>       //json����
#include <QDebug>
#include <QJsonDocument>    //json��ʽ�ĵ�
#include <QJsonParseError>  //json��������

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
