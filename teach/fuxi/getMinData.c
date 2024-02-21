/*
封装一个函数，完成输入三个数值，获取其中最小值
*/

#include <stdio.h>
#include <stdlib.h>

//封装一个函数，传入三个数值，返回值是最小值
int getMinData(int a, int b, int c);

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void fun()
{
	printf("fun\n");
}

int main(int argc, char* argv[])
{
	int min = getMinData(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	printf("min = %d\n", min);
	fun(1);
	fun('c');
	fun("abc");
	
	int a = 10, b = 20;
	swap(&a,&b);
	// a = 20, b = 10;
	printf("a = %d, b = %d\n", a, b);
	
	return 0;
}

int getMinData(int a, int b, int c)
{
	return (a>b?b:a)>c ? c:(a>b?b:a);
}