#include <iostream>
using namespace std;

//定义类
class Data
{
public:
	Data()
	{
		cout << "无参构造函数" << endl;
	}
	Data(int a): a(a)
	{
		cout << "有一个参数的构造函数" << endl;
	}
	Data(int a, int b) : a(a), b(b)
	{
		cout << "有两个参数的构造函数" << endl;
	}
	
	void display()
	{
		cout << "a = " << a << ", b = " << b << endl;
	}
	
private:
	int a;
	int b;
};

int main()
{
	cout << "I'm main!" << endl;
	Data arrays[10];
	arrays[0].display();
	cout << "**************************" << endl;
	Data array[10] = {1,2,3,4,5,6,7,8,9,10}; //类对象数组
	cout << "**************************" << endl;
	Data array1[10] = {Data(1,2) , Data(3,4),  Data(5,6),  Data(7,8),  Data(9,10), Data(11)}; //类对象数组
	cout << "**************************" << endl;
	Data data(1,2), fun[4] = {Data(1,2) , Data(3,4)};
	return 0;
}