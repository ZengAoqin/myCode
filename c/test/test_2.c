#include <stdio.h>


int main()
{
	char str1[50] = "Hello";
    char str2[50] = "World";
    char result[100];
    char extracted_str1[50];
    char extracted_str2[50];
    
    // 拼接字符串
    sprintf(result, "%s:%s", str1, str2);
    printf("拼接后的字符串: %s\n", result);
    
    // 拆分字符串
    sscanf(result, "%s:%s", extracted_str1, extracted_str2);
    printf("拆分后的字符串1: %s\n", extracted_str1);
    printf("拆分后的字符串2: %s\n", extracted_str2);
    
    return 0;
}

