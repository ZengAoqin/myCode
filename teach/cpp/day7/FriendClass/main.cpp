#include <iostream>

using namespace std;

//定义类A
class A
{
    //声明友元类
    friend class B;
public:
    int public_data;
protected:
    int protected_data;
private:
    int private_data;
};

//定义类B
class B
{
public:
    void setDefaultData()
    {
        //实例化A类对象
        data.private_data = 100;    //类A的私有成员
        data.protected_data = 200;  //类A的保护成员
        data.public_data = 300;     //类A的公有成员
    }

    void setData(int m, int n, int num)
    {
        data.private_data = m;
        data.protected_data = n;
        data.public_data = num;
    }

    void showData()
    {
        cout << data.private_data << " "
             << data.protected_data << " "
             << data.public_data << endl;
    }
private:
    A data;
};
int main()
{
    //实例化类B的对象
    B b;
    b.setDefaultData();
    b.showData();

    b.setData(111, 222, 333);
    b.showData();
    return 0;
}
