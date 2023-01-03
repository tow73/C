#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4
#include <stdio.h>
void buildArray(int t[][4])
{
	int i, j;
	int value = 1;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
		{
			t[i][j] = value;
			value++;
		}
}
void printArray(int t[][4])
{
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			printf(" %2d", t[i][j]);
		printf("\n");
	}
	printf("\n");
}
void turnArray(int t[][4], int tu[][4])
{
	int i, j;
	int i2 = 0;
	int j2 = 0;
	for (j = 0; j < SIZE; j++) {
		i2++;
		static i2 = 0;
		for (i = SIZE - 1; i >= 0; i--) {
			tu[i2][j2] = t[i][j];
			j2++;
		}
	}
}
void copyArray(int tu[][4], int t[][4])
{
	int i, j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			t[i][j] = tu[i][j];
}
int main(void)
{
	int table[4][4] = { 0 };
	int turn[4][4] = { 0 };
	int i;
	buildArray(table);
	printArray(table);
	for (i = 0; i < SIZE; i++) {
		turnArray(table, turn);
		printArray(turn);
		copyArray(turn, table);
	}
}