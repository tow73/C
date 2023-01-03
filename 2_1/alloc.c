#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int num, i;
	int* arr;

	//printf("Enter a number: ");
	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));

	for (i = 0; i < num; i++) {
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}

	free(arr);
}