#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void two(char n[])
{
	int len = strlen(n);
	int num = n[len - 1] - 48;

	if (num % 2 == 0)
		printf("1");
	else
		printf("0");
}
int main(void)
{
	char num[51];

	scanf("%s", num);
	two(num);
}