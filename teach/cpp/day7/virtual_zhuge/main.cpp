#include <iostream>

using namespace std;
//����
class User
{
public:
    virtual void show()
    {
        cout << "������ƿ�ʼ" << endl;
    }
};

//�������1
class User1 : public User
{
public:
    void show()
    {
        cout << "�ݼ��ǹ��ϣ���������ʵ" << endl;
    }
};

//�������2
class User2 : public User
{
public:
    void show()
    {
        cout << "�ѳƾ��ݸ漱����Ҫ������" << endl;
    }
};

//�������3
class User3 : public User
{
public:
    void show()
    {
        cout << "������߷��ˣ��赲׷��" << endl;
    }
};

//��Ƶ��ú���
void print(User* user)
{
    user->show();
}

int main()
{
    //�������ָ��
    User* user;
    //��ִ̬��
    User1 user1;   //������
    user = &user1; //��ʽһ
    user->show();

    user = new User2; //��ʽ��
    user->show();

    print(new User3);
    return 0;
}
