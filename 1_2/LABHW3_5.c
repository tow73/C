#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdlib.h> 
#include <time.h>
#include <stdio.h>
void selectionSort(int list[], int size);
int main(void)
{
	int num[SIZE], i;
	srand(time(NULL));
	printf("발생된 난수:   ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", num[i] = rand() % 100);
	printf("\n");
	selectionSort(num, SIZE);
}
void selectionSort(int list[], int size)  //정렬만 남겨두기
{
	int i, j, empty;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (list[i] > list[j])
			{
				empty = list[i];
				list[i] = list[j];
				list[j] = empty;
			}
		}
	}
	printf("정렬 후:       ");  //main에서 출력
	for (i = 0; i < size; i++)
		printf("%d ", list[i]);

	return;
}