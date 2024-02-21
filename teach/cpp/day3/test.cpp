#include <iostream>
using namespace std;

int add(int a, int b, int)
{
	return a+b;
}

int main()
{
	cout << add(3,5, 100) << endl;
	return 0;
}