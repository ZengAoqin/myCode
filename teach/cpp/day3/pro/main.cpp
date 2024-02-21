#include "Data.h"

void Test()
{
	cout << "Test() start" << endl;
	//无参构造函数
	Data data;
	
	Data data1(9527, 25);
	
	Data data2(417, 27, 'E');
	
	cout << "Test() end" << endl;
}

int main()
{
	cout << "hello world!!!" << endl;
	Test();
	cout << "next return" << endl;
	return 0;
}