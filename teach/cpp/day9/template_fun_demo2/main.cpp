#include <iostream>

using namespace std;

//����һ������int�ĺ���func
int func()
{
    cout << "������func()����" << endl;
    return 0;
}
int main()
{
    short a = 5;
    short b = 10;
    short& ra = a;
    //1)���expression��һ��û�����������ı�ʶ����
    //��var��������ñ�ʶ����������ͬ������const���޶�����
    //decltype(ra) da = b;

    //decltype(func) da ;
    //3)���expression��һ����ֵ����ȡ��ַ���ų���һ�������
    //�����������������ı�ʶ������ôvar��������expression������
    //decltype(++a) da;// = b;   //a��short���ͣ�da��short���͵�����
    //decltype(a) da;
    //decltype((a)) da = b;
    //cout << "da = " << da << endl;
    //decltype(func) da ; //da�Ǻ�������
    //decltype((func)) da = func; //da�ͳ��˺���������
    //da();
    //�������������������㣬��var��������expression��������ͬ
    decltype((func)) da = func;
    //da();
    auto dd = func();
    return 0;
}
