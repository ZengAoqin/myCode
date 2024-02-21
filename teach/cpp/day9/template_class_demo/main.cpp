#include <iostream>

using namespace std;

class SuperMan {};
//定义一个类模板
template <class T1, class T2 = string>
class AA
{
public:
    T1 m_a;
    T2 m_b;

    AA() {} //无参构造函数
    AA(T1 a, T2 b): m_a(a), m_b(b) {}
    //通用类型用于函数的返回值
    T1 geta();

    T2 getb();
};

template <class T1, class T2>
T2 AA<T1, T2>::getb()
{
    return m_b;
}

int main()
{
    /*
    AA<int> a;
    a.m_a = 20;
    a.m_b = "Alex";
    cout << "a.geta()=" << a.geta() << endl;
    cout << "a.getb()=" << a.getb() << endl;
    */
    //AA<int, int>* a = new AA<int, int>;
    //a->m_a = 20;
    //a->m_b = 30;
    AA<int>* a = new AA<int>(20, "吕布");
    cout << "a->geta()=" << a->geta() << endl;
    cout << "a->getb()=" << a->getb() << endl;
    delete a;
    return 0;
}

template <class T1, class T2>
T1 AA<T1, T2>::geta()
{
    T1 a = 2;
    return m_a + a;
}
