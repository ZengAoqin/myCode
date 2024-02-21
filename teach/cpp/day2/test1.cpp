#include <iostream>
using namespace std;

int& MyFun()
{
	int var = 10;
	return var;
}

int main(int argc, char* argv[])
{
	int a = 0;
	//a = MyFun(); // waring error
	// int &b = MyFun(); //waring error
	
	return 0;
}