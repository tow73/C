#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5
#include <stdio.h>
void printSet(int s[], int size);
int main(void)
{
	int set[SIZE], i, count = 0;

	for (i = 0; i < SIZE; i++)
	{
		printf("다중집합에 추가할 원소: ");
		scanf("%d", &set[i]);
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