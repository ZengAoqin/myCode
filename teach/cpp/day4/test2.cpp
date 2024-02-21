/*
定义一个类，设计两个字符指针存储5位数字，利用静态成员函数完成大位数乘法
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//创建一个类
class Data
{
public:
	//构造函数
	Data(const char* str1, const char* str2)
	{
		memcpy(a, str1, 5);
		memcpy(b, str2, 5);
	}
	//析构函数
	~Data()
	{

	}
	//静态成员函数申明
	static void A();
	
	void display()
	{
		A();
		cout << b << endl;
	}
private:
	static char* a;
	static char* b;
	static int num;	//静态成员变量
};

//类外初始化

int Data::num = 0;
char* Data::a = new char;
char* Data::b = new char;

void Data::A()
{
	cout << "A()" << endl;
	num = atoi(a)*atoi(b);
	cout << num << endl;
}

int main()
{
	Data data("10000", "54321");
	data.display();
}