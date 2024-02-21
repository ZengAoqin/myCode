#include <iostream>

using namespace std;

template <typename T>
void func(T a)
{
    cout << "func(T a)" << endl;
}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    cout << "func(T1 a, T2 b)" << endl;
}

template <typename T1, typename T2>
void func(T1 a, T2 b, int c)
{
    cout << "func(T1 a, T2 b,int c)" << endl;
}

int main()
{
    func(1);
    func(1, 2);
    func(1, 2, 3);
    return 0;
}
