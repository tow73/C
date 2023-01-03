#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num[5];
	int i, sum, avg;
	sum = 0;

	for(i = 0; i < 5; i++)
	{
		printf("Enter %dth number : ", i + 1);
		scanf("%d", &num[i]);
		sum += num[i];
	}
	avg = sum / 5;

	printf("--------------------\n");
	printf("ÃÑÇÕÀº %d\n", sum);
	printf("Æò±ÕÀº %d\n", avg);
	printf("--------------------\n");

	for (i = 0; i < 5; i++)
		printf("array[%d] : %d\n", i, num[i]);

	return 0;
}