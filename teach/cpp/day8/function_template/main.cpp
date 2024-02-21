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
    cout << "����mySwap����" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */
    string a = "����", b = "��׿";
    mySwap<string>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
