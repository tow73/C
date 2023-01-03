#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selection(int n, int* a)
{
	int i, j, max, temp;

	for (i = 0; i < n - 1; i++) {
		max = 0;
		for (j = 0; j < n - i; j++) {
			if (a[max] < a[j])
				max = j;
		}

		temp = a[max];
		a[max] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
int main(void)
{
	int num, i;
	int* arr;

	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));

	for (i = 0; i < num; i++) {
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}
	printf("\n");

	selection(num, arr);
	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);

	free(arr);
}