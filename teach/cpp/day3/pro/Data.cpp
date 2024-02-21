#include "Data.h"

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