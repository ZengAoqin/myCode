#include "listuser.h"
#include "ui_listuser.h"
#include <QLineEdit>

ListUser::ListUser(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ListUser)
{
    ui->setupUi(this);
}

ListUser::~ListUser()
{
    delete ui;
}

//添加字符串的槽函数，响应点击添加字符串按钮
void ListUser::on_btnString_clicked()
{
    ui->listWidget->addItem("hello");
}

//添加按钮的槽函数，响应点击添加按钮
void ListUser::on_btnButton_clicked()
{
    //1.准备添加的对象
    QPushButton* button = new QPushButton(QString::fromLocal8Bit("按钮"));
    //2.准备列表条目对象
    QListWidgetItem* item = new QListWidgetItem;
    //3.先将空白的条目对象加入到listWidget列表中
    ui->listWidget->addItem(item);
    //4.将列表中的item所占用的窗口设置为添加对象
    ui->listWidget->setItemWidget(item, button);
}

//listwidget双击操作
void ListUser::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    qDebug() << item->text();
    int ret = QMessageBox::information(this, QString::fromLocal8Bit("删除提示"), QString::fromLocal8Bit("是否删除"),
                                       QMessageBox::Yes, QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        //通过列表元素item获取对应的窗口
        QListWidgetItem* itemw = ui->listWidget->currentItem();
        //删除当前选项
        //delete item;
        delete itemw;
    }

}

void ListUser::on_btnWindown_clicked()
{
    //实例化对象
    Form* from = new Form;
    //简单处理为绝对路径
    from->setInfo(QString("C:/Users/RD/Desktop/Share/QT/day05/code/build-Lists-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/app.ico"), QString::number(rand()));

    //条目的创建
    QListWidgetItem* item = new QListWidgetItem;
    //设置item高度和from高度一致
    item->setSizeHint(from->size());
    //先将空白的条目对象加入到listWidget列表中
    ui->listWidget->addItem(item);
    //将列表中的item所占用的窗口设置为添加对象
    ui->listWidget->setItemWidget(item, from);
}

//显示在listview
void ListUser::on_btnStringView_clicked()
{
    QString text = "hello++++"; // 字符串
    //定义字符串列表
    QStringList list;
    list << "hello" << "lisi" << "zhangsan" << text;

    //创建QStringListModel对象
    QStringListModel* model = new QStringListModel;
    //按照模型的内容添加数据
    model->setStringList(list);
    //将模型中的数据添加到listview
    ui->listView->setModel(model);
}
