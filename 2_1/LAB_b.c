#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ST 1
#define LE 2
#define UP 3
int matrixPath_back(int** m, int** M1, int** M2, int** BP, int r, int c)
{
	int a, b;

	if (M2[r][c] != 0)
		return M1[r][c];
	if (r == 0 && c == 0) {
		M1[r][c] = m[r][c];
		BP[r][c] = ST;
		return m[r][c];
	}
	else if (r == 0) {
		M1[r][c] = matrixPath_back(m, M1, M2, BP, r, c - 1) + m[r][c];
		BP[r][c] = LE;
	}
	else if (c == 0) {
		M1[r][c] = matrixPath_back(m, M1, M2, BP, r - 1, c) + m[r][c];
		BP[r][c] = UP;
	}
	else {
		a = matrixPath_back(m, M1, M2, BP, r, c - 1);
		b = matrixPath_back(m, M1, M2, BP, r - 1, c);

		BP[r][c] = (a < b) ? LE : UP;
		
		M1[r][c] = ((a < b) ? a : b) + m[r][c];
	}

	M2[r][c] = 1;
	return M1[r][c];	
}
int main(void)
{
	int** m, ** M1, ** M2, ** BP;
	int i, j, r, c;

	r = c = 4;
	m = (int**)malloc(sizeof(int*) * r);
	M1 = (int**)malloc(sizeof(int*) * r);
	M2 = (int**)malloc(sizeof(int*) * r);
	BP = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M1[i] = (int*)malloc(sizeof(int) * c);
		M2[i] = (int*)malloc(sizeof(int) * c);
		BP[i] = (int*)malloc(sizeof(int) * c);
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf("%d", &m[i][j]);
			M1[i][j] = 0;
			M2[i][j] = 0;
		}
	printf("%d\n", matrixPath_back(m, M1, M2, BP, r - 1, c - 1));

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			printf("%d ", BP[i][j]);
		printf("\n");
	}

	for (i = 0; i < r; i++) {
		free(m[i]);
		free(M1[i]);
		free(M2[i]);
		free(BP[i]);
	}
	free(m);
	free(M1);
	free(M2);
	free(BP);
}