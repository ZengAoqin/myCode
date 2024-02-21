#include <iostream>

int main()
{
	int n;
	/*
	float a;
	char str[10];
	//输入数据
	std::cin >> n >> a >> str;
	
	std::cout <<"n的值为:"<<n<<std::endl;
	std::cout <<"a的值为:"<<a<<std::endl;
	std::cout <<"str的值为:"<<str<<std::endl;
	*/
	std::cin >> n;
	
	//若输入成功
	if(std::cin.good())
	{
		std::cout << "输入成功\n";
	}
	
	//意外情况发生
	if(std::cin.fail())
	{
		std::cout << "输入失败\n";
	}
	return 0;
}