#include <stdio.h>
#include <string.h>


char* func(char *arr1, char *arr2)
{
	return arr2;
}



int main(int argc, char *argv[])
{
	/* int a = 10;
	char b = 'x';
	int* c = &a;
	char* d = &b;
	printf("a=%d b=%c\n", *c, *d);
	printf("&a=%p &b=%p\n", c, d); */
	
	/* char arr[3] = {'a', 'b', 'c'};
	char *p = arr;
	printf("%c\n", p[0]);
	printf("%c\n", *p);
	printf("%c\n", *(p+1));
	
	char *q = "abcde";
	printf("%s\n", q); */
	
	/* printf("argc=%d\n", argc);
	printf("name=%s, argv1=%s\n", argv[0], argv[1]);
	printf("c1=%c\n\n", argv[1][0]); */
	
	/* char *f = func(arr, q);
	printf("%s\n", f); */
	
	/* //数组指针
	int a[3] = {10, 20, 30};
	int (*p)[3] = &a;
	printf("%d\n", (*p)[0]);
	printf("%d\n", *(*p+2));  */
	
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int (*p)[4] = a; 
    printf("%ld\n", sizeof(*(p+1)));
	printf("%d\n", (*(p+1))[0]);
	printf("%d\n", *(*(p+1)+1)); 
	
	/* int a = 10;
	int *p = &a;
	int **q = &p;
	printf("&p=%p, &q=%p\n", p, q); */
	
	/* typedef struct Student
	{
		char name[20];//姓名
		int age;//年龄
		char sex[10];//性别
		float grade;//成绩
	}Stu;
	
	Stu s1 = {"adad", 12, "ad", 36};
	
	Stu s2;
	s2.age = 15;
	s2.grade = 38;
	strcpy(s2.name, "zcnmn");
	strcpy(s2.sex, "af");
	
	Stu p = &s2;
	
	printf("%s\t%d\t%s\t%.2f\n",s1.name,s1.age,s1.sex,s1.grade);
	printf("%s\t%d\t%s\t%.2f\n",s2->name,s2->age,s2->sex,s2->grade);
	 */

	return 0;
}