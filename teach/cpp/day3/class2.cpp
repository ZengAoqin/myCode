#include <iostream>
#include <cstring>
using namespace std;

//定义一个学生的基本信息
class Student
{
	//设定共有权限
public:	
	//成员方法
	//类中声明
	void setName(const char* _name);
	
	char* getName();
	
	void setAge(int _age = 16);
	
	int getAge();
	
	//设定私有权限
private:
	//成员属性
	char name[20];	//姓名
	int age;		//年龄
};

int main()
{
	//实例化学生变量对象
	Student stu;
	//访问成员方法
	stu.setName("Alex");
	//strcpy(stu.name, "Alex");
	stu.setAge(18);
	
	cout << "姓名: " << stu.getName() << endl;
	cout << "年龄: " << stu.getAge() << endl;
	
	//实例化学生指针对象
	Student* pStu = new Student;
	//访问成员方法
	pStu->setName("Rose");
	pStu->setAge();
	cout << "姓名: " << pStu->getName() << endl;
	cout << "年龄: " << pStu->getAge() << endl;
	cout << "sizeof(stu) = " << sizeof(stu) <<endl;
	cout << "sizeof(pStu) = " << sizeof(pStu) <<endl;
	cout << "sizeof(Student) = " << sizeof(Student) <<endl;
	
	delete pStu;
	return 0;
}

//类外的实现接口
//成员方法
void Student::setName(const char* _name)
{
	int len = strlen(_name);
	if(len > 19)
	{
		cout << "传入的名字长度太长" << endl;
		cout << "设置名字无效" << endl;
		return;
	}
	strcpy(name, _name);
}

char* Student::getName()
{
	return name;
}

void Student::setAge(int _age)
{
	age = _age;
}

int Student::getAge()
{
	return age;
}