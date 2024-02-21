#include <iostream>
using namespace std;

//定义个基类
class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	A(int x):x(x)
	{
		cout <<"A(int)" << endl;
	}
	~A()
	{
		cout << "~A()" <<endl;
	}
	void show()
	{
		cout << "A::show()" << endl;
	}
protected:
	int x;
};

class B : virtual public A
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	B(int x, int m, int n):A(x),X(m),Y(n)
	{
		cout << "B(int, int, int)" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
	void show()
	{
		cout << "B::show()" << endl;
	}
protected:
	int X;
	int Y;
};

class C : virtual public A
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	C(int x, int m, int n):A(x),X(m),Y(n)
	{
		cout << "C(int, int, int)" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
	void show()
	{
		cout << "C::show()" << endl;
	}
protected:
	int X;
	int Y;	
};

class D : public B, public C
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	D(int a, int b, int c):A(a),C(a,b,c)
	{
		cout << "D(int, int, int)"<< endl;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
	void show()
	{
		cout << "D::show()" << endl;
		cout << "x = " << x << endl;
	}
};

int main(int argc, char* argv[])
{
	D d(1,3,5);
	d.show();
	return 0;
}


