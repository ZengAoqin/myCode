#include <iostream>
using namespace std;

void fun()
{
	cout << "fun()" << endl;
}

void fun(int a)
{
	cout << "fun(int a)" << endl;
}

/*void fun(const int& a)
{
	cout << "fun(const int& a)" << endl;
}
*/

void fun(int& a)
{
	cout << "fun(int& a)" << endl;
}

double fun(int a, double b)
{
	cout << "fun(int a, double b)" << endl;
	return 0;
}

int main()
{
	int a = 10;
	fun();
	fun(5);
	//fun(a);
	return 0;
}