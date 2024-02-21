#include <iostream>

using namespace std;
template <typename T>
T Add(T a, T b)
{
    return a + b;
}

class CSuperMan {};

int main()
{
    /*
    int a = 10;
    int b = 20;
    int c = Add(a, b);
    cout << "c=" << c << endl;
    */

    /*
    string a = "ÂÀ²¼";
    string b = "¹ØÓğ";
    string c = Add(a, b);
    cout << "c=" << c << endl;
    */

    /*
    CSuperMan a;
    CSuperMan b;
    CSuperMan c = Add(a, b);
    cout << "c=" << c << endl;
    */
    string a = "10";
    const char* b = "20";
    string c = Add<string>(a, b);
    cout << "c=" << c << endl;
    return 0;
}
