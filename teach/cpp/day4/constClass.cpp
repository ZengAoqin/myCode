#include <iostream>
using namespace std;

class A
{
public:
	A(int a): a(a) {}
	//const 修饰在函数尾部，是函数变为只读取，不能修改成员变量的值
	void fun() const
	{
		cout << "A::fun()" << endl;
		//modify();
		//this->a = 100;
		//show();
		cout << "b = " << b;
	}
	void show()
	{
		cout << a << endl;
		cout << b << endl;
	}
	
	void modify()
	{
		this->a = 150;
	}
	static const int b = 200;
private:
	int a;
};

int main()
{
	//实例化对象
	A c(10);
	//c.show();
	c.fun();
	//c.show();
	return 0;
}