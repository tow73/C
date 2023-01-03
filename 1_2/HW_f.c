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

	//가로
	j = col - 1;
	while (j > -1 && b[row][j] == t) {
		count++;
		j--;
	}
	j = col + 1;
	while (j < BOARD_SIZE && b[row][j] == t) {
		count++;
		j++;
	}
	//세로  //count = 1; 넣기  //if(count == 5) 넣기
	i = row - 1;
	while (i > -1 && b[i][col] == t) {
		count++;
		i--;
	}
	i = row + 1;
	while (i < BOARD_SIZE && b[i][col] == t) {
		count++;
		i++;
	}
	//오른쪽 대각선  //count = 1; 넣기  //if(count == 5) 넣기
	i = row - 1;
	j = col + 1;
	while (i > -1 && j < BOARD_SIZE && b[i][j] == t) {
		count++;
		i--;
		j++;
	}
	i = row + 1;
	j = col - 1;
	while (i< BOARD_SIZE && j>-1 && b[i][j] == t) {
		count++;
		i++;
		j--;
	}
	//왼쪽 대각선  //count = 1; 넣기  //if(count == 5) 넣기
	i = row + 1;
	j = col + 1;
	while (i < BOARD_SIZE && j < BOARD_SIZE && b[i][j] == t) {
		count++;
		i++;
		j++;
	}
	i = row - 1;
	j = col - 1;
	while (i > -1 && j > -1 && b[i][j] == t) {
		count++;
		i--;
		j--;
	}
	if (count == 5)
		return 1;
	else
		return 0;
}
int main(void)
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';
	int r, c;
	int i, j;
	int count;
	int win = 1;
	for (i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			board[i][j] = ' ';
	count = 1;
	display(board);
	do
	{
		printf("Player %c(행 열):", turn);
		scanf("%d %d", &r, &c);

		if (board[r][c] != ' ')
			continue;

		board[r][c] = turn;
		display(board);

		if (win = wincheck(board, r, c, turn)) {
			printf("Player %c wins!\n", turn);
			break;
		}

		turn = (turn == 'X' ? 'O' : 'X');
		count++;
	} while (count <= BOARD_SIZE * BOARD_SIZE);

	if (!win)  //!win 으로 쓰기(생각해보기)
		printf("Nobody win!\n");
}