#include <iostream>
using namespace std;

//二级指针申请内存空间
void getMem(int **p)
{
	*p = new int;
}

void destoryMem(int **p)
{
	delete *p;
	*p = NULL;
}

//一级指针的引用申请空间
void getMemEx(int*& p)
{
	p = new int;
}

void destoryMemEx(int*& p)
{
	delete p;
	p = NULL;
}

int main(int argc, char* argv[])
{
	int *ptr = NULL;
	getMem(&ptr);
	*ptr = 200;
	cout << "*ptr = " << *ptr << endl;
	//delete ptr;
	//ptr = NULL;
	destoryMem(&ptr);
	getMemEx(ptr);
	*ptr = 300;
	cout << "*ptr = " << *ptr << endl;
	//delete ptr;
	//ptr = NULL;
	destoryMemEx(ptr);
	return 0;
}