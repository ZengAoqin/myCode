#include <iostream>

using namespace std;

class B
{
public:
    B()
    {

    }

    void setB(int a)
    {
        this->a = a;
    }

    int getBa()
    {
        return a;
    }

private:
    int a;
};

class A
{
public:
    A()
    {
        B();
    }

    void setA(int a)
    {
        this->a = a;
    }

    B getB()
    {
        return b;
    }

    void show()
    {
        cout << "a:" << a << endl;
        cout << "b a:" << b.getBa() << endl;
    }

private:
    int a;
    B b;
};

//int main()
//{
//    A a;
//    a.setA(15);
//    a.getB().setB(20);
//    a.show();

//    return 0;
//}
