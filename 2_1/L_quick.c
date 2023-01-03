#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partician(int* A, int p, int r)
{
	int i = p - 1;
	int j = p;
	int temp;

	for (; j < r; j++) {
		if (A[j] < A[r]) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	i++;
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;

	return i;
}
void quickSort(int* A, int p, int r)
{
	int q;

	if (p < r) {
		q = partician(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main(void)
{
	int num, i;
	int* A;

	scanf("%d", &num);

	A = (int*)malloc(sizeof(int) * num);
	srand(time(NULL));

	for (i = 0; i < num; i++) {
		A[i] = rand() % 1000;
		printf("%d ", A[i]);
	}
	printf("\n");

	quickSort(A, 0, num - 1);

	for (i = 0; i < num; i++)
		printf("%d ", A[i]);

	free(A);
}