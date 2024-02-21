#include <iostream>

using namespace std;
//定义基类
class Base //抽象类
{
public:
    Base(int a)
    {
        cout << "Base(int)" << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }
    //定义纯虚函数
    virtual void show() = 0;
private:
    int a;
};

class Dervice : public Base
{
public :
    Dervice(int a, int b): Base(b), a(a)
    {
        cout << "Dervice" << endl;
    }
    ~Dervice()
    {
        cout << "~Dervice" << endl;
    }
    void show()
    {
        cout << "Dervice::show" << endl;
    }
private:
    int a;
};

int main()
{
    Base* p = new Dervice(5, 3);
    p->show();
    delete p;
    p = NULL;
    return 0;
}
