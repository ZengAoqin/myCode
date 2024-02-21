#include <iostream>

using namespace std;

//������A
class A
{
    //������Ԫ��
    friend class B;
public:
    int public_data;
protected:
    int protected_data;
private:
    int private_data;
};

//������B
class B
{
public:
    void setDefaultData()
    {
        //ʵ����A�����
        data.private_data = 100;    //��A��˽�г�Ա
        data.protected_data = 200;  //��A�ı�����Ա
        data.public_data = 300;     //��A�Ĺ��г�Ա
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
    //ʵ������B�Ķ���
    B b;
    b.setDefaultData();
    b.showData();

    b.setData(111, 222, 333);
    b.showData();
    return 0;
}
