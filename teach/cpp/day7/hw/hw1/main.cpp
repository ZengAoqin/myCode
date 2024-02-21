#include <iostream>

using namespace std;
/*
 * .根据下面的要求，完成程序编写，要求包含main函数并在main中使用所定义类的对象。
(12分)
1）定义一个日期类Date，包含年、月、日；
2）定义一个人事管理的Person类，要求包含身份证号pid、出生日期birthday、性别sex、
姓名name、通讯地址address等属性。其中出生出生日期是日期类的对象；
3）要求Date有构造函数（带默认参数）、显示属性函数showDate()；Person有构造函数
（带默认参数，同时传递给基类构造函数）、显示属性函数showPerson()。
*/
class Date
{
public:
    Date(int year = 2023, int month = 12, int day = 29):
        year(year), month(month), day(day)
    {
        // do nothing
    }
    void showDate()
    {
        cout << year << "年" << month << "月" << day << "日" << endl;
    }
private:
    int year;
    int month;
    int day;
};

class Person
{
public:
    Person(int year, int month, int day, string pid, string sex = "男", string name = "孙悟空", string address = "花果山")
        : pid(pid), birthday(year, month, day),  sex(sex), name(name), address(address)
    {
        // do nothing
    }

    void showPerson()
    {
        cout << "身份证号 " << pid << endl;
        cout << "出生日期 ";
        birthday.showDate();
        cout << "姓名 " << name << endl;
        cout << "性别 " << sex << endl;
        cout << "通讯地址 " << address << endl;
    }
private:
    string pid;     //身份证号
    Date birthday;  //出生日期
    string sex;     //性别
    string name;    //姓名
    string address; //通讯地址
    //要求包含身份证号pid、出生日期birthday、性别sex、
    //姓名name、通讯地址address等属性。其中出生出生日期是日期类的对象
};
int main()
{
    //实例化对象
    Person xiaoMing(2004, 12, 18, "420520", "男", "小明", "武汉软帝");
    xiaoMing.showPerson();
    return 0;
}
