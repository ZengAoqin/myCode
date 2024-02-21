#include <iostream>
using namespace std;

//定义基类1
class A
{
protected:
	int a;
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	void show()
	{
		cout << "A::show()" << endl;
	}
};

class B
{
	int a;
public:
	B()
	{
		cout << "B()" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
	void show()
	{
		cout << "B::show()" << endl;
	}
};

class C: public A, public B
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
	void show()
	{
		A::show();
		B::show();
		cout << A::a << endl;
	}
};

int main()
{
	C c;
	c.show();
	return 0;
}