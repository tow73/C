#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int strToNum(char* s) // 이 함수만 제출
{
	int n;
	char s2[100] = "";

	while (*s) {
		if (isalpha(*s))
			return 0;
		else
			strncat(s2, s, 1);
		s++;
	}
	n = atoi(s2);
	return n;
}
int main(void) // main은 제공
{
	char str[50];

	scanf("%s", str);
	printf("%d\n", strToNum(str));
}
