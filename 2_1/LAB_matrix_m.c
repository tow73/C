#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int matrixPath_memo(int** m, int** M, int r, int c)
{
	if (r == 0 && c == 0)
		return m[r][c];
	else if (r == 0) {
		if (M[r][c - 1] == 0)
			M[r][c - 1] = matrixPath_memo(m, M, r, c - 1);
		return M[r][c - 1] + m[r][c];
	}
	else if (c == 0) {
		if (M[r - 1][c] == 0)
			M[r - 1][c] = matrixPath_memo(m, M, r - 1, c);
		return M[r - 1][c] + m[r][c];
	}
	else {
		if (M[r][c - 1] == 0)
			M[r][c - 1] = matrixPath_memo(m, M, r, c - 1);
		if (M[r - 1][c] == 0)
			M[r - 1][c] = matrixPath_memo(m, M, r - 1, c);
		return ((M[r][c - 1] < M[r - 1][c]) ? M[r][c - 1] : M[r - 1][c]) + m[r][c];
	}
}
int main(void)
{
	int** m, ** M;
	int i,j,r,c;

	r = c = 4;
	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M[i][j] = 0;
		}
	printf("%d\n", matrixPath_memo(m, M, r - 1, c - 1));

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M[i]);
	}
	free(m);
	free(M);
}