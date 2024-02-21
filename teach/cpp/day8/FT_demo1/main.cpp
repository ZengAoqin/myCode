#include <iostream>

using namespace std;

class CSuperMan     //������
{
public:
    template <typename T>
    CSuperMan(T a)
    {
        cout << " a= " << a << endl;
    }
    template <typename T>
    void show(T b)
    {
        cout << " b= " << b << endl;
    }

    template <typename T>
    void Funclass()
    {
        cout << "������Funclass����" << endl;
    }
    ~CSuperMan()
    {
        cout << " ~CSuperMan() " << endl;
    }
};

template <typename anytype>
void mySwap(anytype& a, anytype& b)
{
    anytype tmp = a;
    a = b;
    b = tmp;
}

template <typename anytype>
void show()
{
    cout << "������show����" << endl;
}

int main()
{
    /*
    CSuperMan superman(5);
    superman.show("Alex");
    superman.show(3);
    superman.show("����");
    */
    int a = 10;
    int b = 20; //string b = "20"; �����ˣ�ģ���������ȷ��δ�ҵ�ƥ������غ���
    mySwap(a, b);

    //show(); //���ﺯ�������ˣ������Ƶ�������ʹ��ʲô���Ĳ�����һ��Ҫ��ȷ��������
    show<int>();

    CSuperMan superman(5);
    superman.Funclass<char>();
    return 0;
}
