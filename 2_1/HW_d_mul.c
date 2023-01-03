#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void readMatrix(int** a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%d", &a[i][j]);
}
void mulMatrix(int** a, int** c, int** x, int ar, int ac, int cr, int cc)
{
	int i, j, k;

	for (i = 0; i < ar; i++)
		for (j = 0; j < cc; j++) {
			x[i][j] = 0;
			for (k = 0; k < ac; k++)
				x[i][j] += a[i][k] * c[k][j];
		}
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
void printMatrix2(int** a, int r, int c)
{
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", a[j][i]);
		printf("\n");
	}
}
int main(void)
{
	int** A, ** C, ** X;
	int aRow, aCol, cRow, cCol;  //aCol = cRow
	int i, j;

	printf("행렬 A의 행과 열의 개수: ");
	scanf("%d %d", &aRow, &aCol);
	printf("행렬 C의 행과 열의 개수(C의 행은 %d이어야 함): ", aCol);
	scanf("%d %d", &cRow, &cCol);

	A = (int**)malloc(sizeof(int*) * aRow);
	C = (int**)malloc(sizeof(int*) * cRow);
	X = (int**)malloc(sizeof(int*) * aRow);
	for (i = 0; i < aRow; i++) {
		A[i] = (int**)malloc(sizeof(int*) * aCol);
		X[i] = (int**)malloc(sizeof(int*) * cCol);
	}
		
	for (i = 0; i < cRow; i++)
		C[i] = (int**)malloc(sizeof(int*) * cCol);

	printf("<%d x %d> 행렬 A 입력:\n", aRow, aCol);
	readMatrix(A, aRow, aCol);
	printf("<%d x %d> 행렬 C 입력:\n", cRow, cCol);
	readMatrix(C, cRow, cCol);

	printf("행렬곱:\n");
	mulMatrix(A, C, X, aRow, aCol, cRow, cCol);
	printMatrix(X, aRow, cCol);
	printf("\n");

	printf("전치행렬:\n");
	printMatrix2(A, aCol, aRow);
	printf("\n");

	for (i = 0; i < aRow; i++) {
		free(A[i]);
		free(X[i]);
	}	
	for (i = 0; i < cRow; i++)
		free(C[i]);
	free(A);
	free(C);
	free(X);
}