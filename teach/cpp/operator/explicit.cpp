#include <iostream> //相当于c里面的#include <stdio.h>
#include <string.h>

using namespace std;
//explicit关键字，隐式转换，是指在不需要用户的干预，编译器私下进行的类型转换的行为

//学生类
class Student
{
public:
	Student()
	{
		cout << "Student()" << endl;
	}
	/*explicit*/ Student(int age):m_age(age),m_name("defalut") {}
	/*explicit*/ Student(string name):m_age(18),m_name(name) {}
	
	//显示数据
	void display()
	{
		cout << "m_age = " << m_age << endl;
		cout << "m_name = " << m_name << endl;
	}
	
private:
	int m_age;			//年龄
	string m_name;		//名字
};

int main(int argc, char* argv[])
{
	//实例化学生类的对象
	Student stu1(20);
	stu1.display();
	
	cout << "***************************" << endl;
	
	int a = 25;
	Student stu2 = a; //stu2(25);
	stu2.display();
	/*
	int a = 25;
	Student stu2(a); 
	stu2.display();
	*/
	
	cout << "***************************" << endl;
	
	string str = "Lucky";
	Student stu3 = str;
	//Student stu3(str);
	stu3.display();
	return 0;
}

/*
explicit的作用：
在c++中，explicit关键字用来修饰类的构造函数，被修饰的构造函数，不能发生相应的隐式转换，只能以显示的方法进行类型转换
以显示的方法进行类型转换
explicit使用注意事项：
1)explicit关键字只能用于类内部的构造函数声明上。
2)explicit关键字作用于单个参数的构造函数
*/