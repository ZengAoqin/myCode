#include <iostream>

using namespace std;

string func()
{
    return "��������";
}

int main()
{
    auto a = 3;
    auto b = 3.14;
    auto c = "����";
    cout << " a= " << a << endl;
    cout << " b= " << b << endl;
    cout << " c= " << c << endl;

    auto d = func();
    cout << " d= " << d << endl;
    auto f = a + 3.14;
    cout << " f= " << f << endl;
    return 0;
}
