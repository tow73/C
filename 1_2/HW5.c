#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define X_VALUE 5 //2���� �迭�� ���� ��
#define Y_VALUE 5 //2���� �迭�� ���� ��
void readBombInfo(char grid[][Y_VALUE + 1])
{
	int i;
	// grid �� ���� ���� �Է�
	printf("Input Grid\n");
	for (i = 0; i < X_VALUE; i++)
		scanf("%s", grid[i]); // ������ ���ִ°�? ���ڿ� �������� ����!
}
void countBomb(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++)
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*') {
				if (i - 1 >= 0) {
					numOfBombs[i - 1][j]++;
					if (j - 1 >= 0)
						numOfBombs[i - 1][j - 1]++;
					if (j + 1 < Y_VALUE)
						numOfBombs[i - 1][j + 1]++;
				}
				if (i + 1 < X_VALUE) {
					numOfBombs[i + 1][j]++;
					if (j - 1 >= 0)
						numOfBombs[i + 1][j - 1]++;
					if (j + 1 < Y_VALUE)
						numOfBombs[i + 1][j + 1]++;
				}
				if (j - 1 >= 0)
					numOfBombs[i][j - 1]++;
				if (j + 1 < Y_VALUE)
					numOfBombs[i][j + 1]++;
			}
	/*for (int i2 = i - 1; i2 < i + 2; i2++) {
					for (int j2 = j - 1; j2 < j + 2; j2++) {
						if (i2 >= 0 && j2 >= 0 && i2 < X_VALUE && j2 < Y_VALUE)  //ȿ���� ����, �ڽŵ� ����
							numOfBombs[i2][j2]++;
					}
				}*/
}
void display_numOfBombs(char grid[][Y_VALUE + 1], int numOfBombs[][Y_VALUE])
{
	int i, j;
	for (i = 0; i < X_VALUE; i++) {
		for (j = 0; j < Y_VALUE; j++)
			if (grid[i][j] == '*')
				printf("*");
			else
				printf("%d", numOfBombs[i][j]);
		printf("\n");
	}
}
int main(void)
{
	char grid[X_VALUE][Y_VALUE + 1]; //���ڿ��� ��� �������� NULL�� ���� �ϹǷ�
   // 5X5 �迭�� �ƴ� 5X6 �迭�� �Ǿ�� �Ѵ�.
	int numOfBombs[X_VALUE][Y_VALUE] = { 0 }; //������ ������ �ִ� ������ 5X5 �迭
	readBombInfo(grid);
	countBomb(grid, numOfBombs);
	display_numOfBombs(grid, numOfBombs);
}
