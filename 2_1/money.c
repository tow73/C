#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(int* money, int moneySize, int* picked, int pickSize, int toPick)
{
	int i, smallest;
	int lastIndex = pickSize - toPick - 1;
	int sum = 0;

	for (i = 0; i <= lastIndex; i++)
		sum += money[picked[i]];

	if (sum == 1000 * pickSize) {
		for (i = 0; i <= lastIndex; i++)
			printf("%d ", money[picked[i]]);
		printf("\n");

		return;
	}
	else if (sum > 1000 * pickSize)
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

int main(void) {
	int money[3] = { 1000,5000,10000 };
	int num;

	printf("¼¼¹îµ· ±Ý¾× : ");
	scanf("%d", &num);

	int picked = (int)malloc(sizeof(int) * (num / 1000));

	pick(money, 3, picked, num / 1000, num / 1000);
}