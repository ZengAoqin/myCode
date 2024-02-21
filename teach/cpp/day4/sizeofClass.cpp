#include <iostream>
using namespace std;

//定义类
class Data
{
public:
	//类中的静态成员变量
	static int c;
	void setA(int a)
	{
		this->a = a;
	}
	int getA()
	{
		return a;
	}
	static void setFun(int a)
	{
		//this->a = a; //静态成员函数其实不需要this指针，因为它们是类级别，而不是对象级别，它可以在所有的对象之间共享
		Data::a = a;
		//b = 20; //error: invalid use of member ‘Data::b’ in static member function
	}
private:
    static int a;
	int b;
};

//类外初始化成员变量
int Data::a = 0;
int Data::c = 0;
//int Data::b = 0; // error: ‘int Data::b’ is not a static data member


//int Data::a = 100;
class DataE
{
	
};

int main()
{
	cout << "I'm main" << endl;
	cout << "Data占用" << sizeof(Data) << endl;
	cout << "DataE占用" << sizeof(DataE) << endl;
	Data data; //data对象空间属于栈空间 其中变量a和变量c属于数据段
	cout << "data占用" << sizeof(data) << endl;
	cout << data.c << endl;
	data.c = 200;
	cout << data.c << endl;
	cout << data.getA() << endl;
	data.setA(100);
	cout << data.getA() << endl;
	//静态成员对象是所有的类对象共享的数据
	Data data1, data2;
	cout << data1.getA() << endl;
	cout << data2.getA() << endl;
	//类名直接访问
	cout << Data::c << endl;
	//cout << Data::a << endl; error: ‘int Data::a’ is private
	
	Data::setFun(250);
	cout << data1.getA() << endl;
	cout << data2.getA() << endl;
	
	Data::c = 120;
	return 0;
}