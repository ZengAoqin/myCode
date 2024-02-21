#include <iostream>

using namespace std;

//声明一个返回int的函数func
int func()
{
    cout << "调用了func()函数" << endl;
    return 0;
}
int main()
{
    short a = 5;
    short b = 10;
    short& ra = a;
    //1)如果expression是一个没有用括起来的标识符，
    //则var的类型与该标识符的类型相同，包括const等限定符。
    //decltype(ra) da = b;

    //decltype(func) da ;
    //3)如果expression是一个左值（能取地址）排除第一种情况，
    //或者用括号括起来的标识符，那么var的类型是expression的引用
    //decltype(++a) da;// = b;   //a是short类型，da是short类型的引用
    //decltype(a) da;
    //decltype((a)) da = b;
    //cout << "da = " << da << endl;
    //decltype(func) da ; //da是函数类型
    //decltype((func)) da = func; //da就成了函数的引用
    //da();
    //如果上面的条件都不满足，则var的类型与expression的类型相同
    decltype((func)) da = func;
    //da();
    auto dd = func();
    return 0;
}
