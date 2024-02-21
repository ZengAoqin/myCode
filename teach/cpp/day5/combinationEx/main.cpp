#include <iostream>

using namespace std;
//定义类
class B
{
public:
	//带参构造函数
	B(int a): a(a)
	{
		cout << "B(int )" << endl;
	}
	//析构函数
	~B()
	{
		cout << "~B()" << endl;
	}
	void show()
	{
		cout << "B::a = " << a << endl;
	}
private:
	int a;
};

//组合类
class A
{
public: //公开
	//带参构造函数
	A(int num, int a) :b(num)
	{
		this->a = a;
		//b(num);
		cout << "A(int, int)" << endl;
	}
	//析构函数
	~A()
	{
		cout << "~A()" << endl;
	}
	//显示数据
	void show()
	{
		//b.show(); //b.B::show()
		b.B::show();
		cout << "A::a = " << a << endl;
	}
private: //私有
	int a;
	B b; //另外类的对象，形成类的组合
};

int main(int argc, char* argv[])
{
	cout << "I'm main" << endl;
	//实例化一个对象a
	A a(100,200);
	a.show();
	return 0;
}