#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void insertion(int n, int* a)
{
	int i, j, k, temp;

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (a[i] < a[j])
				break;

		temp = a[i];
		for (k = i; k > j; k--)
			a[k] = a[k - 1];
		a[j] = temp;
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

	insertion(num, arr);
	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);

	free(arr);
}