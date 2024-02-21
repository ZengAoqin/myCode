#include <iostream>
#include <cstring>
using namespace std;

class Room
{
public:
	//自定义构造函数
	Room(int rmData = 123456)
	{
		this->rmNum = new int;
		*rmNum = rmData;
		memcpy(rmName, "幸福小区", sizeof(rmName));
		cout << "Room(int rmData)"<<endl;
	}
	
	//析构函数
	~Room()
	{
		if(this->rmNum != NULL)
			delete rmNum;
		this->rmNum = NULL;
		memset(rmName, 0, sizeof(rmName));
		cout << "~Room()" << endl;
	}
	
	void display()
	{
		cout << "rmName= "<< rmName << "*rmNum=" << *rmNum << endl;
	}
private:
	char rmName[20];
	int* rmNum;
};

int main()
{
	Room rmData(666666);
	rmData.display();
	return 0;
}