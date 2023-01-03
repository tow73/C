#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char askReservation();
void processReservation(int s[][10], int size, int c1, int c2);
void printSeats(int s[][10], int size);
int main(void)
{
	int s1, s2;
	int seats[3][10] = { 0 };
	printf("******�¼� ���� �ý���******\n");
	while (askReservation() == 'y')
	{
		printSeats(seats, 3);
		printf("���° �¼��� �����Ͻðڽ��ϱ�? (�� ��)�� ���·� �Է�: ");
		scanf("%d %d", &s1, &s2);
		processReservation(seats, 3, s1, s2);
		while (getchar() != '\n');
	}
}
char askReservation()
{
	char choice;
	printf("\n�¼��� �����Ͻðڽ��ϱ�?(y/n) ");
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
		printf("����Ǿ����ϴ�.\n");
		printSeats(s, size);
	}
	else
		printf("�̹� ����� �ڸ��Դϴ�.\n");
}