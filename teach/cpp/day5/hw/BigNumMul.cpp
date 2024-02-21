#include <iostream>
#include <cstring>
using namespace std;

//定义一个类
class MathBools
{
public:
	static void BigNum(const char* first, const char* second); //大位数相乘
};

int main(int argc, char* argv[])
{
	char str1[10], str2[10];
	cin >> str1 >> str2;
	MathBools::BigNum(str1, str2);
	return 0;
}


void MathBools::BigNum(const char* first, const char* second)
{
	//获取数据的长度
	int lenF = strlen(first);
	int lenS = strlen(second);
	//定义存储空间
	int result[lenF+lenS];
	memset(result, 0, sizeof(result));
	int i,j;
	//乘法
	for(i = 0; i < lenF; ++i) 
	{
		for(j = 0; j < lenS; ++j) 
		{
			result[i+j+1] += (first[i] - '0')*(second[j] - '0');
		}
	}
	
	//处理result[i]两位数据以上的数据
	for(i = lenF+lenS-1; i > 0; --i)
	{
		if(result[i] >= 10)
		{
			result[i-1] += result[i]/10;
			result[i] %= 10; // result[i] = result[i]%10;
		}
	}
	
	//跳过前面的0
	i = 0;
	while(result[i] == 0) 
		++i;
	
	
	//打印
	for(; i < lenF+lenS; ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}