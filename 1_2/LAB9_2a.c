#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[5];
	printf("문자열을 입력하세요:");
	gets(str1);
	printf("입력한 문자열는 %s\n", str1);
	printf("문자열의 크기는 %d\n", strlen(str1));
}