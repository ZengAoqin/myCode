#include "myhttp.h"


MyHttp::MyHttp(QObject* parent):
    QObject (parent)
{
    m_manager = new QNetworkAccessManager();

    //绑定请求结束信号与响应槽函数
    connect(m_manager, &QNetworkAccessManager::finished, this, &MyHttp::onNetworkReply);
}

MyHttp::~MyHttp()
{
    delete m_manager;
}

//通过url获取HttpJson对象
bool MyHttp::getHttpJsonObject(QString stringUrl, QJsonObject& jsonObj)
{
    //绑定阻塞完毕退出槽函数
    QEventLoop loop;
    connect(this, &MyHttp::requestFinished, &loop, &QEventLoop::quit);

    QUrl url(stringUrl);
    QNetworkRequest request(url);                   //创建了QNetworkRequest对象 封装网络请求
    m_manager->get(request);                        //发送HTTP GET请求
    loop.exec();                                    //阻塞 等待槽函数执行完毕

    //设置jsonObj
    jsonObj = m_jsonObj;

    return m_requestState;
}

//响应槽函数
void MyHttp::onNetworkReply(QNetworkReply *reply)
{
    m_requestState = false;                         //状态默认为false

    if (reply->error() == QNetworkReply::NoError)       //请求成功
    {
        QByteArray data = reply->readAll();
        qDebug() << QString::fromUtf8(data);
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

        if (!jsonDoc.isNull())
        {
            m_jsonObj = jsonDoc.object();
            m_requestState = true;
        }
    }
    else    // 处理请求错误
    {
        qDebug() << "Error: " << reply->errorString();
    }

    reply->deleteLater();

    // 发射信号 通知请求已完成
    emit requestFinished();
}
