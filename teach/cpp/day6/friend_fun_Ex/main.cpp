#include <iostream>
using namespace std;

//声明A类
class A;

//定义类B
class B
{
public:
	void funB(A& data); //将该函数设置为A类的友元函数
};

//定义类A
class A
{
public:
	int public_data;
protected:
	int protected_data;
private:
	int private_data;	
	friend void B::funB(A& data);
};

void B::funB(A& data)
{
	data.private_data = 100;	//私有成员
	data.protected_data = 200;	//保护成员
	data.public_data = 300;		//公有成员
	cout << data.private_data << " "
		 << data.protected_data << " "
		 << data.public_data << " " << endl;
}

int main()
{
	A a;
	B b;
	b.funB(a);
	return 0;
}