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

//����ַ����Ĳۺ�������Ӧ�������ַ�����ť
void ListUser::on_btnString_clicked()
{
    ui->listWidget->addItem("hello");
}

//��Ӱ�ť�Ĳۺ�������Ӧ�����Ӱ�ť
void ListUser::on_btnButton_clicked()
{
    //1.׼����ӵĶ���
    QPushButton* button = new QPushButton(QString::fromLocal8Bit("��ť"));
    //2.׼���б���Ŀ����
    QListWidgetItem* item = new QListWidgetItem;
    //3.�Ƚ��հ׵���Ŀ������뵽listWidget�б���
    ui->listWidget->addItem(item);
    //4.���б��е�item��ռ�õĴ�������Ϊ��Ӷ���
    ui->listWidget->setItemWidget(item, button);
}

//listwidget˫������
void ListUser::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    qDebug() << item->text();
    int ret = QMessageBox::information(this, QString::fromLocal8Bit("ɾ����ʾ"), QString::fromLocal8Bit("�Ƿ�ɾ��"),
                                       QMessageBox::Yes, QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        //ͨ���б�Ԫ��item��ȡ��Ӧ�Ĵ���
        QListWidgetItem* itemw = ui->listWidget->currentItem();
        //ɾ����ǰѡ��
        //delete item;
        delete itemw;
    }

}

void ListUser::on_btnWindown_clicked()
{
    //ʵ��������
    Form* from = new Form;
    //�򵥴���Ϊ����·��
    from->setInfo(QString("C:/Users/RD/Desktop/Share/QT/day05/code/build-Lists-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/debug/app.ico"), QString::number(rand()));

    //��Ŀ�Ĵ���
    QListWidgetItem* item = new QListWidgetItem;
    //����item�߶Ⱥ�from�߶�һ��
    item->setSizeHint(from->size());
    //�Ƚ��հ׵���Ŀ������뵽listWidget�б���
    ui->listWidget->addItem(item);
    //���б��е�item��ռ�õĴ�������Ϊ��Ӷ���
    ui->listWidget->setItemWidget(item, from);
}

//��ʾ��listview
void ListUser::on_btnStringView_clicked()
{
    QString text = "hello++++"; // �ַ���
    //�����ַ����б�
    QStringList list;
    list << "hello" << "lisi" << "zhangsan" << text;

    //����QStringListModel����
    QStringListModel* model = new QStringListModel;
    //����ģ�͵������������
    model->setStringList(list);
    //��ģ���е�������ӵ�listview
    ui->listView->setModel(model);
}
