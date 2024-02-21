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

//json����
void JsonTest::on_btnJson_clicked()
{
    //��������
    QString msg = ui->textEdit->toPlainText();

    //��msg����ת����json��ʽ�ĵ�
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8(), &err);
    //�жϵ�ǰjson����������û�д���
    if(err.error != QJsonParseError::NoError)
    {
        qDebug() << QString::fromLocal8Bit("��ʽ����");
        return;
    }

    //��������
    QJsonObject obj = doc.object(); //��doc����ת��������
    //��ȡ��ֵ��Ӧ������
    QString name = obj.value("name").toString();
    QString sex = obj.value("sex").toString();
    QString qq = obj.value("QQ").toString();
    //��ʾ��ui������
    ui->textBrowser->append(name);
    ui->textBrowser->append(sex);
    ui->textBrowser->append(qq);

    int i = 0;
    //��ȡfriends��Ӧ����������
    QJsonArray array = obj.value("friends").toArray();
    for(i = 0; i < array.count(); ++i)
    {
        //ui->textBrowser->append(array[i].toString());
        ui->textBrowser->append(array.at(i).toString());
    }
}
