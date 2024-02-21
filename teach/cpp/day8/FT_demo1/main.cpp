#include <iostream>

using namespace std;

class CSuperMan     //超人类
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
        cout << "调用了Funclass函数" << endl;
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
    cout << "调用了show函数" << endl;
}

int main()
{
    /*
    CSuperMan superman(5);
    superman.show("Alex");
    superman.show(3);
    superman.show("吕布");
    */
    int a = 10;
    int b = 20; //string b = "20"; 报错了，模板参数不明确，未找到匹配的重载函数
    mySwap(a, b);

    //show(); //这里函数报错了，不能推导出来该使用什么样的参数，一定要明确数据类型
    show<int>();

    CSuperMan superman(5);
    superman.Funclass<char>();
    return 0;
}
