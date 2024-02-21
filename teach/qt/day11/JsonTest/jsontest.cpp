#include "jsontest.h"
#include "ui_jsontest.h"

JsonTest::JsonTest(QWidget* parent) :
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
void JsonTest::on_btnJson_clicked()
{
    //导入数据
    QString msg = ui->textEdit->toPlainText();

    //将msg数据转化成json格式文档
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8(), &err);
    //判断当前json当个事数据没有错误
    if(err.error != QJsonParseError::NoError)
    {
        qDebug() << QString::fromLocal8Bit("格式错误");
        return;
    }

    //解析数据
    QJsonObject obj = doc.object(); //将doc数据转化对象处理
    //获取键值对应的数据
    QString name = obj.value("name").toString();
    QString sex = obj.value("sex").toString();
    QString qq = obj.value("QQ").toString();
    //显示在ui界面上
    ui->textBrowser->append(name);
    ui->textBrowser->append(sex);
    ui->textBrowser->append(qq);

    int i = 0;
    //获取friends对应的数组内容
    QJsonArray array = obj.value("friends").toArray();
    for(i = 0; i < array.count(); ++i)
    {
        //ui->textBrowser->append(array[i].toString());
        ui->textBrowser->append(array.at(i).toString());
    }
}
