#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, i;
	int result = 1;

	printf("Enter a number: ");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
		result *= 2;
	printf("%d", result);
}