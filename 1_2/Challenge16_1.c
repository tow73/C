#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char askReservation();
void processReservation(int s[][10], int size, int c1, int c2);
void printSeats(int s[][10], int size);
int main(void)
{
	int s1, s2;
	int seats[3][10] = { 0 };
	printf("******좌석 예약 시스템******\n");
	while (askReservation() == 'y')
	{
		printSeats(seats, 3);
		printf("몇번째 좌석을 예약하시겠습니까? (열 행)의 형태로 입력: ");
		scanf("%d %d", &s1, &s2);
		processReservation(seats, 3, s1, s2);
		while (getchar() != '\n');
	}
}
char askReservation()
{
	char choice;
	printf("\n좌석을 예약하시겠습니까?(y/n) ");
	scanf("%c", &choice);

	return choice;
}
void printSeats(int s[][10], int size)
{
	int i, j;
	int n = 1;
	printf("------------------------------------------\n");
	printf("\t 1  2  3  4  5  6  7  8  9  10\n");
	printf("------------------------------------------\n");
	for (i = 0; i < size; i++)
	{
		printf("%d\t", n);
		for (j = 0; j < 10; j++)
		{
			printf(" %2d", s[i][j]);

			if (j == 9)
			{
				printf("\n");
				n++;
			}
		}
	}
	printf("\n");

	return;
}
void processReservation(int s[][10], int size, int c1, int c2)
{
	int i;
	if (s[c1 - 1][c2 - 1] == 0)
	{
		s[c1 - 1][c2 - 1] = 1;
		printf("예약되었습니다.\n");
		printSeats(s, size);
	}
	else
		printf("이미 예약된 자리입니다.\n");
}