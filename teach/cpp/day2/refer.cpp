#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int a = 100;	//变量的定义
	int& b = a;		//此时b是a的引用
	
	cout << "&a = " << &a << ", a= " << a << endl;
	cout << "&b = " << &b << ", b= " << b << endl;
	a = 50;
	cout << "a修改之后" << endl;
	cout << "a = " << a << ",b = " << b <<endl;
	b = 100;
	cout << "b修改之后" << endl;
	cout << "a = " << a << ",b = " << b <<endl;
	
	int& c = b;
	cout << "&c = " << &c << ", c= " << c <<endl;
	c = 120;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	
	//int& d;  error: ‘d’ declared as reference but not initialized
	int e = 400;
	c = e; //只是将c的值赋值在400，并不是将的c引用对象在e上
	cout << "*****************" <<endl;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "e=" << e << endl;
	cout << "*****************" <<endl;
	e = 300;
	
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "e=" << e << endl;
	
	//double& da = a; //error: invalid initialization of non-const reference of type ‘double&’ from an rvalue of type ‘double’ 
	
	return 0;
}