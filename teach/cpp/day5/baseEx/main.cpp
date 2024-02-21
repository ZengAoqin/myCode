#include <iostream>

using namespace std;

//定义类
class A
{
public:
	A() //无参构造函数
	{
		cout << "A()" << endl;
	}
	~A() //析构函数
	{
		cout << "~A()" << endl;
	}
};

//定义基类
class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	~Base() //析构函数
	{
		cout << "~Base()" << endl;
	}
	void show()
	{
		cout << "Base::show()" << endl;
	}
public: //公有权限
	int public_data;
protected: //保护权限
	int protected_data;
private: //私有权限
	int private_data;
};

//定义派生类
class Derive : public Base
{
public:
	Derive()
	{
		cout << "Derive()" << endl;
	}
	~Derive()
	{
		cout << "~Derive()" << endl;
	}
	//设置
	void set()
	{
		this->protected_data = 120;		//保护权限
		this->public_data = 111;		//公有权限
	}
	void show()
	{
		Base::show();
		cout << "Derive::show()" << endl;
		cout << protected_data << " " << public_data << endl;
	}
	
private:
	A a;	//内嵌对象
};

int main(int argc, char* argv[])
{
	//实例化一个Derive对象
	Derive derive;
	derive.set();
	//derive.show();
	derive.Base::show();
	return 0;
}