#include <iostream>

using namespace std;
//�������
class Base //������
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
    //���崿�麯��
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
