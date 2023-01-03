#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble(int n, int* a)
{
	int i, temp;

	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}

	for (i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			bubble(n, a);
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

	bubble(num, arr);
	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);

	free(arr);
}