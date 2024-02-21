#include <iostream>

using namespace std;

class B
{
public:
	//构造
	B()
	{
		cout << "B()" << endl;
	}
	//析构
	~B()
	{
		cout << "~B()" << endl;
	}
};

class C
{
public:
	//构造
	C()
	{
		cout << "C()" << endl;
	}
	//析构
	~C()
	{
		cout << "~C()" << endl;
	}
};

class D
{
public:
	//构造
	D()
	{
		cout << "D()" << endl;
	}
	//析构
	~D()
	{
		cout << "~D()" << endl;
	}
};

//定义一个类
class A
{
public:
	//构造
	A()
	{
		cout << "A()" << endl;
	}
	//析构
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	B b; //另外类的对象，形成类的组合
	C c; //另外类的对象，形成类的组合
	D d; //另外类的对象，形成类的组合
};

int main()
{
	cout << "I'm main()" << endl;
	//实例化a对象
	A a;
	return 0;
}