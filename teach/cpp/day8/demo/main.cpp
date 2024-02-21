#include <iostream>

using namespace std;

class Base
{
public:
    virtual void show() = 0;
};

class A : public Base
{
public:
    void show()
    {
        cout << "A::show()" << endl;
    }
};

void print(Base* p)
{
    p->show();
}

int main()
{
    //Base b;
    //b.show();
    Base* p = new A;
    p->show();
    return 0;
}

