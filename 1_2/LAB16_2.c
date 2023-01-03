#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void)
{
	int num[] = { -2, -1, 0, 1, 2 };
	int sum = 0, i = 0;

	while (i < 5)
	{
		sum += num[i];
		i++;
	}
}