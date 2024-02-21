/*
练习：现有教师类和学生类
教师类属性：姓名 年龄 性别 职称 部门
学生类属性：姓名 年龄 性别 学号 成绩
选择公共属性建立基类，然后分别派生得到教室类和学生类，实现数据设置和显示
*/

#include <iostream>
#include <cstring>
using namespace std;

//公共基类
class Person
{
public:
	Person(const char* name, int age, const char* sex):age(age)
	{
		strcpy(this->name, name);
		strcpy(this->sex, sex);
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
	void display()
	{
		cout << "姓名:" << name
			<< ",年龄:" << age
			<< ",性别:" << sex ;
	}
private:
	//姓名 年龄 性别
	char name[20]; 	//姓名
	int age;		//年龄
	char sex[10];	//性别
};

//教师类
class Teacher : public Person
{
public:
	Teacher(const char* name, int age, const char* sex,
			const char* work, const char* pro) : Person(name, age, sex)
	{
		strcpy(this->work, work);
		strcpy(this->pro, pro);
		cout << "Teacher()" << endl;
	}
	~Teacher()
	{
		cout << "~Teacher()" << endl;
	}
	void display()
	{
		Person::display();
		cout << ",职称:" << work
			<<",部门:" << pro << endl;
	}
private:
	//职称 部门
	char work[20];  	//职称
	char pro[20];		//部门
};

//学生类
class Student : public Person
{
public:
	Student(const char* name, int age, const char* sex,
			const char* studentID, float score) : Person(name, age, sex), score(score)
	{
		strcpy(this->studentID, studentID);
		cout << "Student()" << endl;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
	void display()
	{
		Person::display();
		cout << ",学号:" << studentID
			<<",成绩:" << score << endl;
	}
private:
	//学号 成绩
	char studentID[20];  //学号
	float score;		 //部门
};

int main()
{
	//实例化老师的对象
	Teacher teacher("Alex", 20, "男", "教授", "c/c++");
	//实例化学生的对象
	Student student("jack", 18, "男", "10001", 59.5);
	
	teacher.display();
	student.display();
	return 0;
}

