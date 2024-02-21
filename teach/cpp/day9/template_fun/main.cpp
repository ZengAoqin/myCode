#include <iostream>

using namespace std;

class Hero          //Ӣ����
{
public:
    int m_code;     //Ӣ�۱��
    string m_name;  //Ӣ������
    int m_rank;     //Ӣ������
};

template <typename T>
void mySwap(T& a, T& b);        //������������������ֵ�ĺ���ģ��

//�ṩһ������ģ���ػ�,ֻ��������Ӣ�۵�����
template<> void mySwap<Hero>(Hero& hero1, Hero& hero2);
//template<> void mySwap(Hero& hero1, Hero& hero2)

int main()
{
    int a = 10;
    int b = 30;
    mySwap(a, b);
    Hero h1, h2;
    h1.m_code = 1001;
    h1.m_name = "����";
    h1.m_rank = 1;
    h2.m_code = 1002;
    h2.m_name = "������";
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
void mySwap(T& a, T& b)        //���彻������������ֵ�ĺ���ģ��
{
    T tmp = a;
    a = b;
    b = tmp;
    cout << "������mySwap(T& a, T& b)" << endl;
}

template<>
void mySwap<Hero>(Hero& hero1, Hero& hero2)
//template<> void mySwap(Hero& hero1, Hero& hero2)
{
    int tmp = hero1.m_rank;
    hero1.m_rank = hero2.m_rank;
    hero2.m_rank = tmp;
    cout << "������mySwap<Hero>(Hero& hero1, Hero& hero2)" << endl;
}
