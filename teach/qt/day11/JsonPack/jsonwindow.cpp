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
    //实例化json格式对象保存内容
    QJsonObject arrayObj;
    //插入数据给json对象 key-value
    arrayObj.insert("name", name);
    arrayObj.insert("age", age);
    arrayObj.insert("sex", sex);

    //实例化json数组保存多个数据
    QJsonArray arrayObjArray;
    foreach(QString value, friends) //让value字符串去friends字符串列表逐个获取
    {
        arrayObjArray.append(value);
    }

    arrayObj.insert("friend", arrayObjArray);

    return arrayObj;
}

//生成json包
void JsonWindow::on_pushButton_clicked()
{
    //实例化json数据对象
    QJsonObject allobj;
    QJsonArray allarray;

    //创建QStringList存放朋友数据
    //Jack数据
    QStringList names = {C_Z("杨颖"), C_Z("韩红")};
    QJsonObject arrayOBJ = create_Object("Jack", 18, C_Z("男"), names);
    allarray.append(arrayOBJ);
    //Rose数据
    names.clear();
    names << C_Z("小红") << C_Z("小绿");
    arrayOBJ = create_Object("Rose", 19, C_Z("女"), names);
    allarray.append(arrayOBJ);

    allobj.insert("Student", allarray);

    //将打包好的数据转换成字符串
    QJsonDocument doc;
    doc.setObject(allobj);
    QByteArray array = doc.toJson();
    //在UI界面上显示
    ui->textBrowser->append(array);
}
