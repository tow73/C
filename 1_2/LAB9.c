#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 3 // ���Ŀ� 10���� �ٲپ �����Ѵ�
int check(char b[][BOARD_SIZE], int row, int col)
{
	int i, j;
	for(i = 0; i < BOARD_SIZE; i++)
		for (j = 0; j < BOARD_SIZE; j++)
			if (b[row][col] == ' ')
				return 1;
}
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
void main()
{
	char board[BOARD_SIZE][BOARD_SIZE];
	char turn = 'X';
	char turn2 = 'O';
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
		printf("Player %c(�� ��):", turn);
		scanf("%d %d", &r, &c);
		while (check(board, r, c) != 1) {
			printf("Player %c(�� ��):", turn);
			scanf("%d %d", &r, &c);
		}
		board[r][c] = turn;
		display(board);
		count++;
		if (count >= BOARD_SIZE * BOARD_SIZE)
			break;

		printf("Player %c(�� ��):", turn2);  //�̷��� ���� ���� count%2==0�̸� turn='O'�� �ǰ� �ϱ� 
		scanf("%d %d", &r, &c);
		while (check(board, r, c) != 1) {  //do while�� ������(�׳� board[r][c] != ' ')
			printf("Player %c(�� ��):", turn2);
			scanf("%d %d", &r, &c);
		}
		board[r][c] = turn2;
		display(board);
		count++;
	} while (count <= BOARD_SIZE * BOARD_SIZE);
}