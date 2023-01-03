#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printMatrix(int a[][3], int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 3; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
	return;
}
void readMatrix(int a[][3], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			scanf(" %d", &a[i][j]);
	return;
}
void readMatrix2(int a[][2], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 2; j++)
			scanf(" %d", &a[i][j]);
	return;
}
int main(void)
{
	int X[4][2], Y[2][3], Z[4][3];
	int i, j, k;
	printf("(4 x 2) 행렬 X 입력:\n");
	readMatrix2(X, 4);
	printf("(2 x 3) 행렬 Y 입력:\n");
	readMatrix(Y, 2);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++) {
			Z[i][j] = 0;  //맨 앞에서 미리 하기
			for (k = 0; k < 2; k++)
				Z[i][j] += X[i][k] * Y[k][j];
		}			
	printf("행렬곱:\n");
	printMatrix(Z, 4);
	printf("\n");
}
