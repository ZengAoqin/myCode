#include "persion.h"
#include <cstring>

//带参数的构造函数
MAN::Persion::Persion(int _age)
{
	age = new int;
	*age = _age;
	cout << "Persion(int _age)" << endl;
}

//拷贝构造函数(浅拷贝)
/*MAN::Persion::Persion(const Persion& other)
	:age(other.age)
{
	cout << "拷贝构造函数（浅拷贝）" << endl;
}
*/

//拷贝构造函数(深拷贝)
/*MAN::Persion::Persion(const Persion& other)
{
	this->age = new int; //申请新空间
	//memcpy(this->age, other.age, sizeof(int));
	*this->age = 20;
	cout << "拷贝构造函数（深拷贝）" << endl;
}
*/


//析构函数
MAN::Persion::~Persion()
{
	cout << "~Persion()" << endl;
	if(this->age == NULL)
	{
		// do nothing
		cout << "NULL" << endl;
	}
	else
	{
		cout << "not NULL" << endl;
		delete this->age;
		age = NULL;
	}
}

//显示数据
void MAN::Persion::display()
{
	cout << age << ":" << *age << endl;
}

void MAN::Test(Persion p)
{
	cout << " Test Start" << endl;
	p.display();
	cout << " Test End" << endl;
}
