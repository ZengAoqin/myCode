#include <iostream>

using namespace std;

template <typename T>
T Add(T a, T b)
{
    return a + b;
}

template <typename T1, typename T2>
void show(T1 no, T2 msg)
{
    cout << "������" << no << "��:" << msg << endl;
}

int main()
{
    int no = 9527;        //Ӣ�۱��
    string msg = "̫ţ��";        //���͵�����
    show(no, msg);
    return 0;
}
