#include <iostream>

using namespace std;

class Hero          //英雄类
{
public:
    int m_code;     //英雄编号
    string m_name;  //英雄姓名
    int m_rank;     //英雄排名
};

template <typename T>
void mySwap(T& a, T& b);        //声明交换两个变量的值的函数模板

//提供一个函数模板特化,只交换两个英雄的排名
template<> void mySwap<Hero>(Hero& hero1, Hero& hero2);
//template<> void mySwap(Hero& hero1, Hero& hero2)

int main()
{
    int a = 10;
    int b = 30;
    mySwap(a, b);
    Hero h1, h2;
    h1.m_code = 1001;
    h1.m_name = "雷神";
    h1.m_rank = 1;
    h2.m_code = 1002;
    h2.m_name = "钢铁侠";
    h2.m_rank = 2;
    mySwap(h1, h2);
    cout << "h1.m_code = " << h1.m_code << endl;
    cout << "h1.m_name = " << h1.m_name << endl;
    cout << "h1.m_rank = " << h1.m_rank << endl;
    cout << "**************************" << endl;
    cout << "h2.m_code = " << h2.m_code << endl;
    cout << "h2.m_name = " << h2.m_name << endl;
    cout << "h2.m_rank = " << h2.m_rank << endl;
    return 0;
}

template <typename T>
void mySwap(T& a, T& b)        //定义交换两个变量的值的函数模板
{
    T tmp = a;
    a = b;
    b = tmp;
    cout << "调用了mySwap(T& a, T& b)" << endl;
}

template<>
void mySwap<Hero>(Hero& hero1, Hero& hero2)
//template<> void mySwap(Hero& hero1, Hero& hero2)
{
    int tmp = hero1.m_rank;
    hero1.m_rank = hero2.m_rank;
    hero2.m_rank = tmp;
    cout << "调用了mySwap<Hero>(Hero& hero1, Hero& hero2)" << endl;
}
