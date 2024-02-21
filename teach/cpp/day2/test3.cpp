#include <iostream>
using namespace std;

int myFun(int arg)
{
	return arg*2;
}

int main(int argc, char* argv[])
{
	int a = 10;		//定义变量
	int* p = &a; 	//定义指针
	cout << "*p = " << *p << endl; //打印10
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	int*& ptr = p;  //指针的引用
	
	*ptr = 30;
	cout << "通过指针的引用修改变量的值\n";
	cout << "*p = " << *p <<" a= " << a << endl;
	cout << "*ptr = " << *ptr << endl;
	
	int (*fun)(int) = myFun; //函数指针
	cout << "fun(5) = " << fun(5) << endl;
	int (*&pfun)(int) = fun; //函数指针的引用
	cout << "调用函数指针的引用" <<endl;
	cout << "pfun(20) = " << pfun(20) << endl;
	
	int (*pArr)[20]; //数组指针
	int arr[20];
	for(int i = 0; i < 20; ++i)
	{
		*(arr+i) = i+1;
	}
	
	pArr = &arr;
	
	for(int i = 0; i < 20; i++)
	{
		//cout << "(*pArr)[" << i << "] = " << (*pArr)[i] << endl;
		cout << "*(*pArr)(" << i << ") = " << *(*(pArr)+i) << endl;
	}
	cout << "********************" << endl;
	cout << "调用数组指针的引用" << endl;
	int(*&ppArr)[20] = pArr; //数组指针的引用
	for(int i = 0; i < 20; i++)
	{
		cout << "(*ppArr)[" << i << "] = " << (*ppArr)[i] << endl;
		//cout << "*(*ppArr)(" << i << ") = " << *(*(ppArr)+i) << endl;
	}
	
	return 0;
}