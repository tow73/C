#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void readMatrix(int** a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}
void addMatrix(int** a, int** b, int** x, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			x[i][j] = a[i][j] + b[i][j];
}
void printMatrix(int** a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int** A, ** B, ** X;
	int aRow, aCol;
	int i, j;

	printf("행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);

	A = (int**)malloc(sizeof(int*) * aRow);
	B = (int**)malloc(sizeof(int*) * aRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++) {
		A[i] = (int**)malloc(sizeof(int*) * aCol);
		B[i] = (int**)malloc(sizeof(int*) * aCol);
		X[i] = (int**)malloc(sizeof(int*) * aCol);
	}
	
	printf("<%d x %d> 행렬 A 입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("<%d x %d> 행렬 B 입력:\n", aRow, aCol);
	readMatrix(B, aRow, aCol);

	printf("행렬합:\n");
	addMatrix(A, B, X, aRow, aCol);
	printMatrix(X, aRow, aCol);
	printf("\n");

	for (i = 0; i < aRow; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}
	free(A);
	free(B);
	free(X);
}