#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count = 0;

void pick(int* money, int moneySize, int* picked, int pickSize, int toPick)
{
	int i, smallest;
	int lastIndex = pickSize - toPick - 1;
	int sum = 0;

	for (i = 0; i <= lastIndex; i++)
		sum += money[picked[i]];

	if (sum == 10 * pickSize) {
		count++;
		return;
	}
	else if (sum > 10 * pickSize)
		return;

	if (toPick == pickSize)
		smallest = 0;
	else
		smallest = picked[lastIndex];

	for (i = smallest; i < moneySize; i++) {
		picked[lastIndex + 1] = i;
		pick(money, moneySize, picked, pickSize, toPick - 1);
	}
	return;
}
int main(void)
{
	int money[4] = { 10,50,100,500 };
	int num;

	scanf("%d", &num);

	if (num % 10 == 0) {
		int picked = (int)malloc(sizeof(int) * (num / 10));
		pick(money, 4, picked, num / 10, num / 10);
	}

	printf("%d", count);
}