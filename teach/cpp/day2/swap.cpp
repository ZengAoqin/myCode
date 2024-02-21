#include <iostream>
using namespace std;

void swap1(int a, int b) //数值传递
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void swap2(int* a, int* b) //地址传递
{
	*a = (*a)^(*b);
	*b = (*a)^(*b);
	*a = (*a)^(*b);
}

void swap3(int& a,int& b) //引用传递
{
	a = a^b;
	b = a^b;
	a = a^b;
}

int main(int argc, char* argv[])
{
	int m = 3, n = 5;
	/*
	cout << "swap2交换之前" << endl;
	cout << "m = " << m << ",n = " << n << endl;
	cout << "swap2交换之后" << endl;
	swap2(&m,&n);
	cout << "m = " << m << ",n = " << n << endl;
	*/
	cout << "swap3交换之前" << endl;
	cout << "m = " << m << ",n = " << n << endl;
	cout << "swap3交换之后" << endl;
	swap3(m,n);
	cout << "m = " << m << ",n = " << n << endl;
	return 0;
}