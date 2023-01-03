#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int mul[8][10];
	int i, j, pick;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 9; j++)
			mul[i][j] = (i + 2) * (j + 1);

	printf("--구구단 표는 다음과 같습니다.\n");
	for(i = 0; i < 8; i++)
		for (j = 0; j < 9; j++)
		{
			printf(" %3d", mul[i][j]);

			if (j == 8)
				printf("\n");
		}

	printf("--원하는 구구단은? ");
	scanf("%d", &pick);

	for (j = 0; j < 9; j++)
		printf(" %3d", mul[pick - 2][j]);
	printf("\n");
}