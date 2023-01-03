#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char award[][7], int awardSize, int* picked, int pickSize, int toPick)
{
	int i, lastIndex, smallest;

	if (toPick == 0) {
		for (i = 0; i < pickSize; i++)
			printf("%7s ", award[picked[i]]);
		printf("\n");

		return;
	}

	lastIndex = pickSize - toPick - 1;
	if (toPick == pickSize)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < awardSize; i++) {
		picked[lastIndex + 1] = i;
		pick(award, awardSize, picked, pickSize, toPick - 1);
	}
}
int main(void)
{
	char award[][7] = { "공유", "김수현", "송중기", "지성", "현빈" };
	int num;

	printf("인기상 몇명? ");
	scanf("%d", &num);

	int picked = (int)malloc(sizeof(int) * num);

	pick(award, 5, picked, num, num);
}