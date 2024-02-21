#include <iostream>

using namespace std;

double func(/*int a, */double b, const char* c, float d, short e, long f)
{
    cout /*<< "a = " << a */ << ",b = " << b << ",c = " << c << ",d = " << d
                             << ",e = " << e << ",f = " << f << endl;
    return 3.14;
}

int main()
{
    double (*pf)(/*int, */double, const char*, float, short, long);
    pf = func;
    pf(/*1, */3.14, "隔壁老王", 2.2, 3, 5);

    auto pf1 = func;
    pf1(/*1, */3.14, "隔壁老王", 2.2, 3, 5);
    return 0;
}
