#include <iostream>
using namespace std;

int global_var = 8;

int& myFun1()
{
	return global_var;
}

int& myFun2()
{
	static int c = 4;
	return c;
}

int main(int argc, char* argv[])
{
	/*返回引用作为右值*/
	int a = myFun1();
	cout << "a = " << a << endl;
	
	//返回引用作为左值
	myFun1() = 12;
	cout << "global_var = " << global_var << endl;
	
	//通过引用去接受函数的返回值，引用也可以修改其值
	int& b = myFun1();
	cout << "b = " << b << endl;
	b = 15;
	cout << "global_var = " << global_var << endl;
	
	//静态局部变量
	myFun2() = 25;
	cout << "myFun2() = " << myFun2() << endl;
	
	int& d = myFun2();
	d = 250;
	cout << "myFun2() = " << myFun2() << endl;
	return 0;
}