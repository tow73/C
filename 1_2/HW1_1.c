#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main(void)
{
	int data[100], count[10] = { 0 };
	int num, i, j;
	srand(time(NULL));

	printf("Enter the number of random numbers:(<= 100): ");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		data[i] = rand() % 10;

		for (j = 0; j < 10; j++)
			if (data[i] == j)   //if�� ���� ���ٷ� ������
				count[j]++;
	}
	for (j = 0; j < 10; j++)
		printf("%d�� ������ %d\n", j, count[j]);

	printf("--------------------------------------------------\n");
	printf("�߻��� ������\n");

	for (i = 0; i < num; i++)
	{
		if (i % 5 == 0)
			printf("\n");
		printf("%5d", data[i]);
	}
}