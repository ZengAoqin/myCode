#include <iostream>
using namespace std;

//定义一个类
class Data
{
public:
	//自定义无参构造函数
	Data();
	
	//参数列表赋值方式
	Data(int id, int age);
	
	Data(int id, int age, char);
	
	//自定义析构函数
	~Data();
	
private:
	int id, age;
};

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

//自定义无参构造函数
Data::Data()
{
	id = 0;
	age = 0;
	cout << "Data()" << endl;
}

Data::Data(int id, int age)
	: id(id), age(age)
{
	cout << "Data(int id, int age)" << endl;
}

Data::Data(int id, int age, char)
{
	this->id = id;
	this->age = age;
	cout << "Data(int id, int age, char)" << endl;
}
//自定义析构函数
Data::~Data()
{
	cout << "~Data()"  << "id = " << id << ",age = " << age << endl;
}