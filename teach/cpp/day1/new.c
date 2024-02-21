#include <iostream>
using namespace std;

int main()
{
	//定义变量指针
	char* ctr = new char('A');
	int* ptr = new int(100);
	char* str = new char[15]; //申请连续的内存空间
	int* itr = new int[10];
	
	//获取指针指向的数据
	cout << *ctr << endl;
	cout << *ptr << endl;
	cout << ctr << endl; //char类型特殊一字节
	cout << ptr[0] << endl;
	
	delete ctr;
	delete ptr;
	delete []str;
	delete []itr;
	return 0;
}