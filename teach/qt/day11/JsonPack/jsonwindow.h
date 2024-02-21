#ifndef JSONWINDOW_H
#define JSONWINDOW_H

#include <QWidget>
#include <QJsonObject>      //json����
#include <QJsonArray>       //json����
#include <QDebug>
#include <QJsonDocument>    //json��ʽ�ĵ�
#include <QJsonParseError>  //json��������

namespace Ui
{
class JsonWindow;
}

class JsonWindow : public QWidget
{
    Q_OBJECT

public:
    explicit JsonWindow(QWidget* parent = nullptr);
    ~JsonWindow();
    QJsonObject create_Object(QString name, int age, QString sex, QStringList friends);

private slots:
    void on_pushButton_clicked();

private:
    Ui::JsonWindow* ui;
};

#endif // JSONWINDOW_H
