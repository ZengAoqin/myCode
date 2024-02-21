#include "jsontest.h"
#include "ui_jsontest.h"

JsonTest::JsonTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JsonTest)
{
    ui->setupUi(this);
}

JsonTest::~JsonTest()
{
    delete ui;
}

//json解析
void JsonTest::on_pushButton_clicked()
{
    QString msg = ui->textEdit->toPlainText();

    //将msg转为json格式文档
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8(), &err);

    //判断当前json格式是否错误
    if(err.error != QJsonParseError::NoError)
    {
        qDebug() << "格式错误";
        return;
    }

    //将doc数据转为json对象
    QJsonObject obj = doc.object();
    QString name = obj.value("name").toString();
    ui->textBrowser->append(name);

    //获取数组
    int i;
    QJsonArray arr = obj.value("friends").toArray();
    for(i = 0; i < arr.count(); ++i)
    {
        ui->textBrowser->append(arr[i].toString());
    }

}

//json打包
void JsonTest::on_pushButton_2_clicked()
{
    //实例化json对象
    QJsonObject obj;
    obj["name"] = "张三";
    obj["age"] = 14;

    QJsonArray arr;
    arr.append("哈哈还是");
    arr.append("考个研怕");
    arr.append("俞飞鸿吗");
    obj["friends"] = arr;

    //第二个对象
    QJsonObject obj1;
    obj1["name"] = "安魁克";
    obj1["age"] = 3636;

    QJsonArray arr1;
    arr1.append("啊烦烦烦");
    arr1.append("三个哥哥");
    arr1.append("十分丰富");
    obj1["friends"] = arr1;

    //添加到json数组
    QJsonArray arr_obj;
    arr_obj.append(obj);
    arr_obj.append(obj1);

    QJsonDocument doc(arr_obj);
    QString text = doc.toJson();
    ui->textBrowser->append(text);
}

//解析天气
void JsonTest::on_pushButton_3_clicked()
{
    //打开并读取文件
    QString filePath = QFileDialog::getOpenFileName(this);
    QFile file;
    file.setFileName(filePath);
    file.open(QFile::ReadOnly);
    QByteArray jsonData = file.readAll();

    //转为json文档
    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    QJsonObject jsonObject = doc.object();

    //解析
    QString reason = jsonObject["reason"].toString();
    qDebug() << "Reason:" << reason;
    ui->textBrowser->append("Reason:" + reason);

    QJsonObject resultObject = jsonObject["result"].toObject();
    QString city = resultObject["city"].toString();
    qDebug() << "City:" << city;
    ui->textBrowser->append("City:" + city);

    QJsonObject realtimeObject = resultObject["realtime"].toObject();
    QString temperature = realtimeObject["temperature"].toString();
    QString humidity = realtimeObject["humidity"].toString();
    QString info = realtimeObject["info"].toString();
    QString wid = realtimeObject["wid"].toString();
    QString direct = realtimeObject["direct"].toString();
    QString power = realtimeObject["power"].toString();
    QString aqi = realtimeObject["aqi"].toString();

    qDebug() << "Realtime - Temperature:" << temperature;
    qDebug() << "Realtime - Humidity:" << humidity;
    qDebug() << "Realtime - Info:" << info;
    qDebug() << "Realtime - wid:" << wid;
    qDebug() << "Realtime - direct:" << direct;
    qDebug() << "Realtime - power:" << power;
    qDebug() << "Realtime - aqi:" << aqi;
    ui->textBrowser->append("Realtime - Temperature:" + temperature);
    ui->textBrowser->append("Realtime - Humidity:" + humidity);
    ui->textBrowser->append("Realtime - Info:" + info);
    ui->textBrowser->append("Realtime - wid:" + wid);
    ui->textBrowser->append("Realtime - direct:" + direct);
    ui->textBrowser->append("Realtime - power:" + power);
    ui->textBrowser->append("Realtime - aqi:" + aqi);

    int i;
    QJsonArray futureArray = resultObject["future"].toArray();
    qDebug() << "Future Forecast:";
    ui->textBrowser->append("Future Forecast:");
    for (i = 0 ; i < futureArray.size(); ++i) {
        QJsonObject futureObject = futureArray[i].toObject();
        QString date = futureObject["date"].toString();
        QString tempRange = futureObject["temperature"].toString();
        QString weather = futureObject["weather"].toString();
        QString direct = futureObject["direct"].toString();
        QJsonObject wid = futureObject["wid"].toObject();
        QString day = wid["day"].toString();
        QString night = wid["night"].toString();

        qDebug() << "Date:" << date;
        qDebug() << "Temperature Range:" << tempRange;
        qDebug() << "Weather:" << weather;
        qDebug() << "wid - day:" << day;
        qDebug() << "wid - night:" << night;
        qDebug() << "Direct:" << direct;

        ui->textBrowser->append("Date:" + date);
        ui->textBrowser->append("Temperature Range:" + tempRange);
        ui->textBrowser->append("Weather:" + weather);
        ui->textBrowser->append("wid - day:" + day);
        ui->textBrowser->append("wid - night:" + night);
        ui->textBrowser->append("Direct:" + direct);
    }
}
