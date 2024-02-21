#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int a = 4;		//定义变量a
	const int& b = a;
	cout << "a = " << a << " b= " << b << endl; 
	//b = 5; //error: assignment of read-only reference ‘b’
	a = 5;
	cout << "修改之后" << endl;
	cout << "a = " << a << " b= " << b << endl; 
	
	const int c = 20;
	const int& e = c; //ok
	//int& d = c; //error: binding ‘const int’ to reference of type ‘int&’ discards qualifiers
	
	const int& f = 100;
	return 0;
}