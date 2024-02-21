#include <iostream>

using namespace std;
//在继承情况下，使用普通函数操作，对象调用父子类函数
//基类
class Base
{
public:
    Base()
    {
        cout << "Base()" << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }
    virtual void show()
    {
        cout << "Base::show()" << endl;
    }
};

//定义派生类
class Dervice : public Base
{
public:
    Dervice()
    {
        cout << "Dervice()" << endl;
    }
    ~Dervice()
    {
        cout << "~Dervice()" << endl;
    }
    void show()
    {
        cout << "Dervice::show()" << endl;
    }
};

int main()
{
    //基类对象
    Base b;
    b.show();
    //派生类
    Dervice d;
    d.show();
    //通过派生类对象初始化基类指针
    Base* ptr = new Dervice;
    ptr->show();
    Base* ptr1 = new Base;
    ptr1->show();

    return 0;
}
