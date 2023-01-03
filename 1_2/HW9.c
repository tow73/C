#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 10
void display(char b[][BOARD_SIZE])
{
	char ch;
	int i, j;
	printf(" ");
	for (i = 0; i < BOARD_SIZE; i++)
		printf("%2d", i);
	printf("\n ---------------------\n");
	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%3d |", i);
		for (j = 0; j < BOARD_SIZE; j++)
			printf(" %c", b[i][j]);
		printf("\n");
	}
}
int wincheck(char b[][BOARD_SIZE], int row, int col, char t)
{
	int i, j;
	int count = 1;

	//����
	j = col - 1;
	while (j < 0 && b[row][j] == t) {
		count++;
		j--;
	}
	j = col + 1;
	while (j > BOARD_SIZE && b[row][j] == t) {
		count++;
		j++;
	}
	//����
	i = row - 1;
	while (i < 0 && b[i][col] == t) {
		count++;
		i--;
	}
	i = row + 1;
	while (i > BOARD_SIZE && b[i][col] == t) {
		count++;
		i++;
	}
	if (count == 5)
		return 1;
	else
		return 0;
}
int main(void)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn;
	int r, c;
	int i, j;
	int count;
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';
	count = 1;
	display(board);
	do
	{
		if (count % 2 == 0)
			turn = 'X';
		else
			turn = 'O';

		do {
			printf("Player %c(�� ��):", turn);
			scanf("%d %d", &r, &c);
		} while (board[r][c] != ' ');

		if (wincheck(board, r, c, turn) == 1) {
			printf("Player %c wins!\n", turn);
			return 0;  //�� ���� �� ���� �׸��� ���� �� �ᵵ �� ��..?
		}

		board[r][c] = turn;
		display(board);
		count++;
	} while (count <= BOARD_SIZE * BOARD_SIZE);

	if (count > BOARD_SIZE * BOARD_SIZE && wincheck(board, r, c, turn) == 0)  //!win ���� ����(�����غ���)
		printf("Nobody win!\n");
}