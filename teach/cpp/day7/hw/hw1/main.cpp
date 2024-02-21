#include <iostream>

using namespace std;
/*
 * .���������Ҫ����ɳ����д��Ҫ�����main��������main��ʹ����������Ķ���
(12��)
1������һ��������Date�������ꡢ�¡��գ�
2������һ�����¹����Person�࣬Ҫ��������֤��pid����������birthday���Ա�sex��
����name��ͨѶ��ַaddress�����ԡ����г�������������������Ķ���
3��Ҫ��Date�й��캯������Ĭ�ϲ���������ʾ���Ժ���showDate()��Person�й��캯��
����Ĭ�ϲ�����ͬʱ���ݸ����๹�캯��������ʾ���Ժ���showPerson()��
*/
class Date
{
public:
    Date(int year = 2023, int month = 12, int day = 29):
        year(year), month(month), day(day)
    {
        // do nothing
    }
    void showDate()
    {
        cout << year << "��" << month << "��" << day << "��" << endl;
    }
private:
    int year;
    int month;
    int day;
};

class Person
{
public:
    Person(int year, int month, int day, string pid, string sex = "��", string name = "�����", string address = "����ɽ")
        : pid(pid), birthday(year, month, day),  sex(sex), name(name), address(address)
    {
        // do nothing
    }

    void showPerson()
    {
        cout << "���֤�� " << pid << endl;
        cout << "�������� ";
        birthday.showDate();
        cout << "���� " << name << endl;
        cout << "�Ա� " << sex << endl;
        cout << "ͨѶ��ַ " << address << endl;
    }
private:
    string pid;     //���֤��
    Date birthday;  //��������
    string sex;     //�Ա�
    string name;    //����
    string address; //ͨѶ��ַ
    //Ҫ��������֤��pid����������birthday���Ա�sex��
    //����name��ͨѶ��ַaddress�����ԡ����г�������������������Ķ���
};
int main()
{
    //ʵ��������
    Person xiaoMing(2004, 12, 18, "420520", "��", "С��", "�人���");
    xiaoMing.showPerson();
    return 0;
}
