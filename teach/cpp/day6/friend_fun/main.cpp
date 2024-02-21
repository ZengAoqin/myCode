#include <iostream>
using namespace std;


void info();

//定义类
class Data
{
public:
	int public_data;
	//在类中声明show函数为友元函数
	friend void show();
	
	
protected:
	int protected_data;
private:
	int private_data;
	
	friend void info()
	{
		cout << "info()" << endl;
		cout << "****************" << endl;
		//实例化对象
		Data data;
		data.private_data = 100;	//私有成员
		data.protected_data = 200;	//保护成员
		data.public_data = 300;		//公有成员
		cout << data.private_data << " "
			 << data.protected_data << " "
			 << data.public_data << " " << endl;
		cout << "****************" << endl;
	}
	
};

void show()
{
	cout << "show()" << endl;
	cout << "****************" << endl;
	//实例化对象
	Data data;
	data.private_data = 100;	//私有成员
	data.protected_data = 200;	//保护成员
	data.public_data = 300;		//公有成员
	cout << data.private_data << " "
		 << data.protected_data << " "
		 << data.public_data << " " << endl;
	cout << "****************" << endl;
}



int main(int argc, char* argv[])
{
	show();
	info();
	return 0;
}

