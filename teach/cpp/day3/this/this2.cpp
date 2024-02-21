#include <iostream>
using namespace std;

class Data
{
public: //共享权限
	int a;
	
	//普通返回this本身对象
	Data fun1()
	{
		this->a++; //记录数据
		return *this;
	}
	
	//引用返回this本身对象
	Data& fun2()
	{
		this->a++; //记录数据
		return *this;
	}
};

int main()
{
	Data data;
	data.a = 100;
	cout << data.a << endl;
	cout << (data.fun1().fun1().fun1().fun1().fun1()).a << endl;
	cout << data.a << endl;
	cout << "====================" << endl;
	data.a = 100;
	cout << data.a << endl;
	cout << (data.fun2().fun2().fun2()).a << endl;
	cout << data.a << endl;
	return 0;
}