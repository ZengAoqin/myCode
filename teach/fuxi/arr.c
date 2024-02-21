#include <stdio.h>

int main()
{
	/* //arr++和++arr
	int arr[10] = {11,22,33,44,55,66,77,88,99,0};
	int *p = arr;
	printf("p = %p\n", p); 
	
	printf("p++ = %p\n", p++); 
	printf("p = %p\n", p); //*(arr+1)
	
	printf("++p = %p\n", ++p); 
	printf("p = %p\n", p); 
	
	printf("sizeof(arr) = %ld\n", sizeof(arr)); */ 
	
	
	/* int a[2][3]; //2个元素，每个元素是一维3个数的类型int[3]
	printf("a = %p\n", a); // a[0]
	printf("a+1 = %p\n", a+1); //a[1]  3*4
	printf("sizeof(a) = %ld\n", sizeof(a));
	printf("sizeof(a[0]) = %ld\n", sizeof(a[0])); */
	
	
	
 	int b[2][3][4]; //2个元素，每个元素是二维3*4的int[3][4]
	
	printf("b = %p\n", b);    
	printf("&b = %p\n", &b);
	printf("&b+1 = %p\n", &b+1);  // 2*3*4*4 96
	printf("b+1 = %p\n", b+1); // &b[1]  3*4*4 //&b[0]+1
	printf("&b[0]+1 = %p\n", &b[0]+1);
	printf("b[0] = %p\n", b[0]); //&b[0][0]
	printf("b[0]+1 = %p\n", b[0]+1); //&b[0][1] 16
	printf("b[0][0] = %p\n", b[0][0]); //&b[0][0][0]
	printf("b[0][0]+1 = %p\n", b[0][0]+1); //&b[0][0][1]
	
	printf("&b[0][0] = %p\n", &b[0][0]); // &b[0][0] -->&b[0][1]
	printf("&b[0][0]+1 = %p\n", &b[0][0]+1);
	printf("sizeof(b) = %ld\n", sizeof(b)); 
	
	
	
	/*
	 int a[100]={[0 ... 30]=10,[31 ... 60]=20,[61 ... 99]=30};
	 printf("a[25] = %d\n", a[25]);
	 printf("a[10] = %d\n", a[10]);
	 */
	 /* int a[] = {1,2,3,4,5,76,7,234,12,123,123,435,4657,567,234,12312,123123,999};
	 int b[][3][4];
	printf("len = %ld\n", sizeof(a)/sizeof(int)); */
	
	return 0;
}