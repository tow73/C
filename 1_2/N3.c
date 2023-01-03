#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void splitString(char* str, char* s1, char* s2) // 이 함수만 제출
{
	*s1 = '\0';
	*s2 = '\0';
	while (*str) {
		strncat(s1, str, 2);
		str++;
		str++;
		strncat(s2, str, 2);
		str++;
		str++;
	}
}
int main(void)
{

	char str[50], s1[50], s2[50];

	scanf("%s", str);
	splitString(str, s1, s2);

	printf("%s\n", s1);
	printf("%s\n", s2);
}