#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble(int n, int* a)
{
	int i, temp;
	static int count = -1;

	count++;
	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}

	printf("i = %d:", count);
	for (i = 0; i < n; i++)
		printf("%3d", a[i]);
	printf("\n");

	for (i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
			bubble(n, a);
}
int main(void)
{
	int num, i;
	int* arr;

	printf("Enter a number: ");
	scanf("%d", &num);

	arr = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));

	printf("초기 :");
	for (i = 0; i < num; i++) {
		arr[i] = rand() % 100;
		printf("%3d", arr[i]);
	}
	printf("\n");

	bubble(num, arr);

	printf("정렬 :");
	for (i = 0; i < num; i++)
		printf("%3d", arr[i]);
	printf("\n");

	free(arr);
}