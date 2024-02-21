#include "jsonwindow.h"
#include "ui_jsonwindow.h"
#define C_Z(x) QString::fromLocal8Bit(x)

JsonWindow::JsonWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::JsonWindow)
{
    ui->setupUi(this);
}

JsonWindow::~JsonWindow()
{
    delete ui;
}

QJsonObject JsonWindow::create_Object(QString name, int age, QString sex, QStringList friends)
{
    //ʵ����json��ʽ���󱣴�����
    QJsonObject arrayObj;
    //�������ݸ�json���� key-value
    arrayObj.insert("name", name);
    arrayObj.insert("age", age);
    arrayObj.insert("sex", sex);

    //ʵ����json���鱣��������
    QJsonArray arrayObjArray;
    foreach(QString value, friends) //��value�ַ���ȥfriends�ַ����б������ȡ
    {
        arrayObjArray.append(value);
    }

    arrayObj.insert("friend", arrayObjArray);

    return arrayObj;
}

//����json��
void JsonWindow::on_pushButton_clicked()
{
    //ʵ����json���ݶ���
    QJsonObject allobj;
    QJsonArray allarray;

    //����QStringList�����������
    //Jack����
    QStringList names = {C_Z("��ӱ"), C_Z("����")};
    QJsonObject arrayOBJ = create_Object("Jack", 18, C_Z("��"), names);
    allarray.append(arrayOBJ);
    //Rose����
    names.clear();
    names << C_Z("С��") << C_Z("С��");
    arrayOBJ = create_Object("Rose", 19, C_Z("Ů"), names);
    allarray.append(arrayOBJ);

    allobj.insert("Student", allarray);

    //������õ�����ת�����ַ���
    QJsonDocument doc;
    doc.setObject(allobj);
    QByteArray array = doc.toJson();
    //��UI��������ʾ
    ui->textBrowser->append(array);
}
