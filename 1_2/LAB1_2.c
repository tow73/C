#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
int main(void)
{
	int data[100];
	int num, i, max;
	max = -999;
	srand(time(NULL));

	printf("Enter the number of random numbers:(<= 50): ");
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{
		data[i] = rand() % 100;

		if (data[i] > max)
			max = data[i];
	}

	printf("�ִ밪�� %d\n", max);
	printf("--------------------------------------------------\n");
	printf("�߻��� ������\n");

	for (i = 0; i < num; i++)
	{
		if (i % 5 == 0)  //0��� 4�ᵵ ��
			printf("\n");
		printf("%5d", data[i]);
	}

	return 0;
}