#include <iostream>

using namespace std;


int num = 88;

void swap(int& i, int& j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

int& func1()
{
    return num;
}

int& func2()
{
    static int snum = 99;
    return snum;
}

int main(int argc, char* argv[])
{
    int& x = func2();
    cout << "x=" << x << endl;
    func2() = 66;
    cout << "func2()=" << func2() << endl;
    // func2() = 15;
    // cout << "num=" << num << endl;
    
    // int m = 11, n = 22;

    // swap(m, n);

    // cout << "m=" << m << endl;
    // cout << "n=" << n << endl <<endl;

    // int a = 100;
    // int& b = a;

    // cout << "&a=" << &a << endl;
    // cout << "a=" << a << endl;
    // cout << "&b=" << &b << endl;
    // cout << "b=" << b << endl << endl;

    // a = 50;
    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl << endl;

    // b = 100 ;
    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl << endl;

    // int& c = b;
    // cout << "&c=" << &c << endl;
    // cout << "c=" << c << endl << endl;

    // c = 120;
    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl;
    // cout << "c=" << c << endl << endl;

    // int e = 400;
    // c = e; //赋值 非引用
    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl;
    // cout << "c=" << c << endl;
    // cout << "e=" << e << endl << endl;

    // e = 300;
    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl;
    // cout << "c=" << c << endl;
    // cout << "e=" << e << endl << endl;

    // int g = 15;
    // const int& f = g;
    // cout << "f=" << f << endl;
    // cout << "a=" << g << endl;

    return 0;
}