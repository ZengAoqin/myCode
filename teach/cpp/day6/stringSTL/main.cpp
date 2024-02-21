#include <iostream>
using namespace std;

int main(int argc, char* argv[]) 
{
	string name1("jack"); 	//构造函数赋值
	string name2(10,'h'); 	//构造函数赋值10个字符h
	string name3 = "rose"; 	//赋值运算符
	
	cout << "name1 = " << name1 << endl;
	cout << "name2 = " << name2 << endl;
	cout << "name3 = " << name3 << endl;
	
	string str = "helloworld";
	cout << str.length() << " " << str.size()<< endl;
	//获取下标为2的元素
	char ch = str[2]; //下标运算符[]
	cout << ch << endl;
	char sh = str.at(2); //函数获取
	cout << sh << endl;
	
	string str1 = "welcome";
	string str2 = " jack ma";
	string strs = str1 + str2;
	cout << strs << endl;
	
	//完成两个字符串交互位置
	cout << "*********************" << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	str1.swap(str2);
	cout << "*********************" << endl;
	cout << str1 << endl;
	cout << str2 << endl;
	
	string s = "hello", c = "hello";
	//if(s == c) //运算符实现
	if(s.compare(c) == 0) //函数
	{
		cout << "s和c的值相等" << endl;
	}
	else
	{
		cout << "s和c的值不相等" << endl;
	}
	
	//字符创的追加
	string ctrs = "你好";
	ctrs += str1;
	cout << ctrs << endl;
	string vtrs = "你好!!!";
	vtrs.append(str1);
	cout << vtrs << endl;
	
	//将对象转化为C语言标准字符串指针
	const char* p = str1.c_str();
	cout << p << endl;
	
	//清空
	//str1 = "";
	str1.clear();
	
	//if(str1 == "")
	if(str1.empty())
	{
		cout << "str1字符串为空" << endl;
	}
	
	//字符串的母串查询子串是否存在
	string a("welcome wuhan");
	int index = a.find("wu");
	cout << index << endl;
	
	//字符串删除
	string q = a.erase(2, 5); //删除字符串从2开始删除5个字符
	cout << q << endl;
	cout << a << endl;
	
	//字符串中的数据替换
	a = a.replace(2, 5, "HELLO");
	cout << a << endl; //weHELLOn
	
	//字符串中的数据插入
	a.insert(2, "TEST "); //从下标2后面开始插入一个数据weTEST HELLOn
	cout << a << endl;
	a.insert(5, 10, 'A'); //从下标5后面开始插入10个字符'A' weTESAAAAAAAAAAT HELLOn
	cout << a << endl;
	
	//将字符串的内容拷贝给char*指针
	char buf[30] = {0};
	a.copy(buf, 20, 0); //拷贝20个字符，从角标0（开始位置）开始拷贝//weTESAAAAAAAAAAT HEL
	cout << buf << endl;
	return 0;
}