#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int* A, int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int t = 0;
	int* B = (int*)malloc(sizeof(int) * (r - p + 1));

	while (i <= q && j <= r) {
		if (A[i] < A[j]) {
			B[t] = A[i];
			i++;
		}
		else {
			B[t] = A[j];
			j++;
		}
		t++;
	}
	if (i > q)
		for (; j <= r; j++) {
			B[t] = A[j];
			t++;
		}
	else
		for (; i <= q; i++) {
			B[t] = A[i];
			t++;
		}
		
	t = 0;
	for (i = p; i <= r; i++) {
		A[i] = B[t];
		t++;
	}

	free(B);
}
void mergeSort(int* A, int p, int r)
{
	int q;

	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
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

	mergeSort(A, 0, num - 1);
	
	for (i = 0; i < num; i++)
		printf("%d ", A[i]);

	free(A);
}