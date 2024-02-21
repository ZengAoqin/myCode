#include <iostream>

using namespace std;
/*
auto func(int x, double y)->int
{
    cout << "µ÷ÓÃÁËfunc(int x, double y)" << endl;
    return 0;
}
*/
template <typename T1, typename T2>
auto func(T1 x, T2 y)->decltype(x + y)
{
    //    auto tmp = x + y;
    decltype(x + y) tmp = x + y;
    cout << "tmp=" << tmp;
    return tmp;
}


int main()
{
    //auto x = func(1, 3.14);
    //cout << "x=" << x << endl;
    func(3, 5.18);
    return 0;
}
