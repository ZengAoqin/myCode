#include <iostream>
using namespace std;

//定义基类
class A
{
public:
	//无参构造函数
	A()
	{
		cout << "A()" << endl;
	}
	//带参数的构造函数
	A(int a): private_data(a)
	{
		cout << "A(int)" << endl;
	}
	void show()
	{
		cout << "A::show()" << endl;
		cout << "我是A::private_data = " << private_data << endl;
	}
	//析构函数
	~A()
	{
		cout << "~A()" << endl;
	}
public:
	int public_data;
protected:
	int protected_data;
private:
	int private_data;
};

//派生类
class B: protected A
{
public:
	//无参构造函数
	B()
	{
		cout << "B()" << endl;
	}
	//带参数的构造函数
	B(int a,int num):a(a)
	{
		cout << "B(int, int)" << endl;
		//cout << "我在B里面，A::private_data = " << A::private_data << endl;
		A::protected_data = 10;
		cout << "我在B里面，A::protected_data = " << A::protected_data << endl;
	}
	void show()
	{
		cout << "B::show()" << endl;
		cout << "protected_data = " << protected_data << ", public_data = " << public_data << endl;
		//cout << "private_data = " << private_data;
	}
	//析构函数
	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int a; //派生类成员
};

class C: public B
{
public:
	void CC()
	{
		cout << "C::CC()" << endl;
		cout << "protected_data = " << protected_data << ", public_data = " << public_data << endl;
	}
};

int main(int argc, char* argv[])
{
	//B b(12,13);
	//b.show();
	//b.public_data = 10;
	//b.protected_data = 111;
	//b.protected_data = 10;
	//b.public_data = 11;
	C c;
	c.show();
	return 0;
}