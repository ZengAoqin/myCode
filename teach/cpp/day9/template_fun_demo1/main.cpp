#include <iostream>

using namespace std;
//��ͨ����
void mySwap(int a, int b)
{
    cout << "��������ͨ����" << endl;
}

//ģ�庯��
template <typename T>
void mySwap(T a, T b)
{
    cout << "�����˺���ģ��" << endl;
}

//���廯�ĺ���ģ��
template <>
void mySwap(int a, int b)
{
    cout << "�����˾��廯�ĺ���ģ��" << endl;
}

int main()
{
    //mySwap(1, 2);
    //mySwap<>(1, 2);
    mySwap('1', '2');
    return 0;
}
