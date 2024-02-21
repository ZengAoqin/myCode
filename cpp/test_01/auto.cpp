#include <iostream>
#include <string>

using namespace std;

template <typename T>
void func(T& a, T& b)
{
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

template<>
void func<string>(string& a1, string& a2)
{
    cout << "String" << endl;
    cout << "a:" << a1 << endl;
    cout << "b:" << a2 << endl;
}

template <typename T1, typename T2>
auto func1(T1& a, T2& b)->decltype (a + b)
{
    auto c = a + b;
    return c;
}

//int main()
//{
//    int a = 1, b = 2;
//    func(a, b);

//    string c = "asd", d = "hhh";
//    func(c, d);

//    int e = 5;
//    double f = 3.14;
//    auto g = func1(e, f);
//    cout << "g:" << g << endl;

//    return 0;
//}
