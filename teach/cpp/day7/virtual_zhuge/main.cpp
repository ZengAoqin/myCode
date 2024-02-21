#include <iostream>

using namespace std;
//基类
class User
{
public:
    virtual void show()
    {
        cout << "锦囊妙计开始" << endl;
    }
};

//锦囊妙计1
class User1 : public User
{
public:
    void show()
    {
        cout << "拜见乔国老，宣扬结婚事实" << endl;
    }
};

//锦囊妙计2
class User2 : public User
{
public:
    void show()
    {
        cout << "谎称荆州告急，需要返荆州" << endl;
    }
};

//锦囊妙计3
class User3 : public User
{
public:
    void show()
    {
        cout << "含泪哭诉夫人，阻挡追兵" << endl;
    }
};

//设计调用函数
void print(User* user)
{
    user->show();
}

int main()
{
    //定义基类指针
    User* user;
    //多态执行
    User1 user1;   //派生类
    user = &user1; //方式一
    user->show();

    user = new User2; //方式二
    user->show();

    print(new User3);
    return 0;
}
