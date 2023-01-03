#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#include <stdio.h>
char askReservation();  //int�� �ٲٱ�
void printSeats(int s[], int size);
void processReservation(int s[], int size, int seatNumber);
int main(void)
{
	int seatChoice, sum = 0;
	int seats[SIZE] = { 0 };
	printf("******�¼� ���� �ý���******\n");

	while (processReservation != 1)
	{
		printSeats(seats, SIZE);
		if (sum == 10)
			return 0;
		seatChoice = askReservation();
		sum += seatChoice;
		processReservation(seats, SIZE, sum);
	}
}
char askReservation()  //int�� �ٲٱ�
{
	int n;
	printf("�¼��� �����Ͻðڽ��ϱ�?(���) ");
	scanf("%d", &n);

	return n;
}
void processReservation(int s[], int size, int seatNumber)
{
	int i;
	for (i = 0; i < seatNumber; i++)
		s[i] = 1;
}
void printSeats(int s[], int size)
{
	int i;
	printf("----------------------\n");
	printf(" 1 2 3 4 5 6 7 8 9 10\n");
	printf("----------------------\n");
	for (i = 0; i < size; i++)
		printf("%2d", s[i]);
	printf("\n");

	return 0;
}