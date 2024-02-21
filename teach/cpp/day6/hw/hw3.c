/*
有100个人打分，如果有超过一半的人打分是一样的 ，打分范围1~100000分，三个人99 99 50 返回这个值99
4个人， 90 90 80 80 返回0

int getScore(const int* socreloist, int _sizeofscore)
{
}

*/

#include <stdio.h>

int getScore(const int* socreloist, int _sizeofscore)
{
	//打分的次数
	int arr[100001] = {0};
	int i = 0;
	int maxScoreCount = 0; //打分次数最多的人数
	int fScore = 0; //最终分数
	for(i = 0; i < _sizeofscore; ++i)
	{
		if(socreloist[i] < 1 || socreloist[i] > 100000) //打分范围1~100000分
		{
			printf("无效分数\n"); //无效分数跳过这个分数
			continue;
		}
		
		arr[socreloist[i]]++;
	}
	
	for(i = 1; i < 100001; ++i)
	{
		if(maxScoreCount < arr[i])
		{
			maxScoreCount = arr[i];
			fScore = i;
		}
	}
	
	return maxScoreCount > _sizeofscore/2 ? fScore:0;
}

int main(int argc, char* argv[])
{
	int sorelist[] = {99,50,99,100,99};
	printf("FinalScore = %d\n",getScore(sorelist, sizeof(sorelist)/sizeof(int)));
	return 0;
}