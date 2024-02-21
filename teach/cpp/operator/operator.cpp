#include <iostream>
using namespace std;

class Student
{
	//friend是友元关键字, Student是返回值类型 operator+函数名
	friend Student operator+(Student a, Student b)
	{
		//实例化对象
		Student stu;
		stu.m_math = a.m_math + b.m_math;
		stu.m_english = a.m_english + b.m_english;
		return stu;
	}
public:
	//无参构造函数
	Student() {}
	Student(float _math, float _english) //两个参数的构造函数
	{
		this->m_math = _math;
		this->m_english = _english;
	}
	Student operator-(Student a) //类重载运算符-
	{
		Student stu;
		stu.m_math = m_math - a.m_math;
		stu.m_english = m_english - a.m_english;
		return stu;
	}
	//显示数据
	void display()
	{
		cout << "m_math = " << m_math << endl;
		cout << "m_english = " << m_english << endl;
	}
	
private:
	float m_math;			//数学成绩
	float m_english;		//英语成绩
};

/*
运算符重载：
赋予运算符另一种作用，实现自定义类型的运算
实质：operator和运算符当做是函数名，函数体里面是实现运算的细节
*/
//operator+
/*
这里有三种方法来实现：
1)友元函数重载
参数个数=操作数
2)类重载
参数个数=操作数-1
*/

int main(int argc, char* argv[])
{
	Student stu1(50, 60);
	Student stu2(60, 70);
	Student stu3 = stu1+stu2;
	stu3.display();
	cout << "***********************" << endl;
	Student stu4(10, 11.5);
	Student stu5 = stu3-stu4;
	stu5.display();
	return 0;
}