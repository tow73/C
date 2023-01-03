#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partician(int* a, int p, int r)
{
	int i = p - 1;
	int j = p;
	int temp;

	for (; j < r; j++) {
		if (a[j] < a[r]) {
			i++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	i++;
	temp = a[i];
	a[i] = a[r];
	a[r] = temp;

	return i;
}
int selection(int* a, int p, int r, int i)
{
	int q = partician(a, p, r);
	int s = q - p + 1;

	if (i == s)
		return a[q];
	else if (i > s)
		return selection(a, q + 1, r, i - s);
	else
		return selection(a, p, q - 1, i);
}
int main(void)
{
	int num, small, i;
	int* arr;

	printf("Enter the number of numbers: ");
	scanf("%d", &num);
	printf("몇 번째로 작은 수: ");
	scanf("%d", &small);

	arr = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));

	for (i = 0; i < num; i++) {
		arr[i] = rand() % 1000;
		printf("%d ", arr[i]);
	}
	printf("\n%d번째로 작은 수는 %d\n", small, selection(arr, 0, num - 1, small));

	free(arr);
}