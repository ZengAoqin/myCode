#include <iostream>

using namespace std;
//�ڼ̳�����£�ʹ����ͨ����������������ø����ຯ��
//����
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

//����������
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
    //�������
    Base b;
    b.show();
    //������
    Dervice d;
    d.show();
    //ͨ������������ʼ������ָ��
    Base* ptr = new Dervice;
    ptr->show();
    Base* ptr1 = new Base;
    ptr1->show();

    return 0;
}
