#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int big(int* a, int n)
{
	int* b = (int*)malloc(sizeof(int) * n);
	int i, j;
	int k = 0;
	int max = -999;

	for (i = 0; i < n; i++)
		b[i] = 1;
	for (i = 0; i < n; i++) {
		a[k]++;
		for (j = 0; j < n; j++)
			b[i] *= a[j];
		a[k]--;
		k++;
	}
	for (i = 0; i < n; i++) {
		if (b[i] > max)
			max = b[i];
	}
	return max;
}
int main(void)
{
	int num;
	int* arr;

	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	printf("%d\n", big(arr, num));

	free(arr);
}