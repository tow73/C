#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void readMatrix(int a[][3], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
}
void addMatrix(int a[][3], int b[][3], int x[][3], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int a[][3], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int A[3][3], B[3][3], X[3][3];

	printf("<3 x 3> 행렬 A 입력:\n");
	readMatrix(A, 3);
	printf("<3 x 3> 행렬 B 입력:\n");
	readMatrix(B, 3);

	printf("행렬합:\n");
	addMatrix(A, B, X, 3);
	printMatrix(X, 3);
}