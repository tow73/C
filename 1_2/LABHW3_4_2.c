#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
void printSet(int s[], int size);
int main(void)
{
	int set[SIZE], i, j, count = 0;

	for (i = 0; i < SIZE; i++)
	{
		printf("�������տ� �߰��� ����: ");
		scanf("%d", &set[i]);

		for (j = 0; j < i; j++)
		{
			if (set[i] == set[j])
			{
				printf("%d�� �̹� ���տ� ����\n", set[i]);  //�Լ� ���� ���� ����� ����
				printf("�������տ� �߰��� ����: ");
				scanf("%d", &set[i]);
			}
			else if (i == j - 1)
				break;
		}
		count++;
		printSet(set, count);
	}
}
void printSet(int s[], int size)
{
	int i;

	printf("{ ");
	for (i = 0; i < size; i++)
	{
		printf("%d", s[i]);

		if (size - 1 > i)
			printf(", ");
	}
	printf(" }\n");

	return;
}