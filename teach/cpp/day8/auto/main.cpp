#include <iostream>

using namespace std;

string func()
{
    return "¸ô±ÚÀÏÍõ";
}

int main()
{
    auto a = 3;
    auto b = 3.14;
    auto c = "ÂÀ²¼";
    cout << " a= " << a << endl;
    cout << " b= " << b << endl;
    cout << " c= " << c << endl;

    auto d = func();
    cout << " d= " << d << endl;
    auto f = a + 3.14;
    cout << " f= " << f << endl;
    return 0;
}
