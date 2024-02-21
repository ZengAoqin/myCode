#include <iostream>

using namespace std;

template <typename anytype>
void mySwap(anytype& a, anytype& b)
{
    anytype tmp = a;
    a = b;
    b = tmp;
}

/*
void mySwap(string& a, string& b)
{
    string tmp = a;
    a = b;
    b = tmp;
}

void mySwap(double& a, double& b)
{
    double tmp = a;
    a = b;
    b = tmp;
}
*/

int main()
{
    /*
    int a = 10, b = 30;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    mySwap(a, b);
    cout << "调用mySwap函数" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */
    string a = "吕布", b = "董卓";
    mySwap<string>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
