#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//不允许用sscanf, ftok
//10.10.10.1
int chage(const char* ip)
{
	//判断数组的长度
	int len = strlen(ip);
	char str[len+1],buf[10];
	char* p = str;
	memset(str, 0, sizeof(str));
	strcpy(str, ip);
	int arr[4] = {0};
	memset(buf, 0, sizeof(buf));
	int i = 0 , j;
	for(j = 0; j < 3; ++j)
	{
		i = 0;
		memset(buf, 0, sizeof(buf));
		while(*p != '.')
		{
			buf[i++] = *p;
			p++;
		}
		p++; //跳过.
		arr[j] = atoi(buf);
	}
	
	i = 0;
	memset(buf, 0, sizeof(buf));
	while(*p != '\0')
	{
		buf[i++] = *p;
		p++;
	}
	arr[3] = atoi(buf);
	
	return arr[0]*256*256*256 + arr[1]*256*256 + arr[2]*256 + arr[3];
}

int main(int argc, char* argv[])
{
	int value = chage("1.3.6.9");
	printf("value = %d\n", value);
	return 0;
}