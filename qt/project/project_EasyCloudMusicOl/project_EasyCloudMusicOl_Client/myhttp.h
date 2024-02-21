#ifndef MYHTTP_H
#define MYHTTP_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <config.h>


class MyHttp : public QObject
{
    Q_OBJECT

signals:
    void requestFinished();

//成员函数
public:
    explicit MyHttp(QObject* parent);
    ~MyHttp();
    bool getHttpJsonObject(QString stringUrl, QJsonObject& jsonObj);    //通过url获取HttpJson对象

private slots:
    void onNetworkReply(QNetworkReply *reply);          //响应槽函数

//成员变量
private:
    QNetworkAccessManager* m_manager;                   //Qt网络访问
    QJsonObject m_jsonObj;                              //json对象
    bool m_requestState;                                //请求状态
};

#endif // MYHTTP_H
