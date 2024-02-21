#include "listuser.h"
#include "ui_listuser.h"
#include <QPushButton>
#include <QListWidgetItem>
#include <QLineEdit>
#include "itemform.h"
#include <QStringListModel>


ListUser::ListUser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ListUser)
{
    ui->setupUi(this);
}

ListUser::~ListUser()
{
    delete ui;
}

//添加字符串
void ListUser::on_pb_string_clicked()
{
    ui->listWidget->addItem("Hello");
}

//添加按钮
void ListUser::on_pb_button_clicked()
{
    //准备btn对象
    QPushButton* button = new QPushButton("按钮");
    //准备列表条目对象
    QListWidgetItem* item = new QListWidgetItem();
    //将条目对象加入listwidget
    ui->listWidget->addItem(item);
    //将窗口设置为条目对象
    ui->listWidget->setItemWidget(item, button);
}

//添加输入框
void ListUser::on_pb_lineEdit_clicked()
{
    //准备lineEdit对象
    QLineEdit* edit = new QLineEdit();
    //准备列表条目对象
    QListWidgetItem* item = new QListWidgetItem();
    //将条目对象加入listwidget
    ui->listWidget->addItem(item);
    //将窗口设置为条目对象
    ui->listWidget->setItemWidget(item, edit);
}

//双击listWidget中的条目删除
void ListUser::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
//    delete item;

    QListWidgetItem* c_item = ui->listWidget->currentItem();
    delete c_item;
}

//添加窗口
void ListUser::on_pb_widget_clicked()
{
    //准备widget对象
    ItemForm* itemform = new ItemForm();
    itemform->setInfo("D:/share/qt/practice/practice_qlist/img/big.ico", QString::number(rand()));
    //准备列表条目对象
    QListWidgetItem* item = new QListWidgetItem();
    //设置大小
    item->setSizeHint(itemform->size());
    //将条目对象加入listwidget
    ui->listWidget->addItem(item);
    //将窗口设置为条目对象
    ui->listWidget->setItemWidget(item, itemform);
}


void ListUser::on_pb_listString_clicked()
{
    QString text = "hello";

    //定义字符串列表
    QStringList list;
    list << "abc" << "def" << text;
    //定义model
    QStringListModel* model = new QStringListModel();
    //设置list
    model->setStringList(list);
    ui->listView->setModel(model);
}
