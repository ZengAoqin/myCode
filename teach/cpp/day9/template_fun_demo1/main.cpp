#include <iostream>

using namespace std;
//普通函数
void mySwap(int a, int b)
{
    cout << "调用了普通函数" << endl;
}

//模板函数
template <typename T>
void mySwap(T a, T b)
{
    cout << "调用了函数模板" << endl;
}

//具体化的函数模板
template <>
void mySwap(int a, int b)
{
    cout << "调用了具体化的函数模板" << endl;
}

int main()
{
    //mySwap(1, 2);
    //mySwap<>(1, 2);
    mySwap('1', '2');
    return 0;
}
