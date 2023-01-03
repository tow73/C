#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char ball[], int ballSize, int* picked, int pickSize, int toPick)
{
	int i, lastIndex, smallest;

	if (toPick == 0) {
		for (i = 0; i < pickSize; i++)
			printf("%c ", ball[picked[i]]);
		printf("\n");

		return;
	}

	lastIndex = pickSize - toPick - 1;
	if (toPick == pickSize)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < ballSize; i++) {
		picked[lastIndex + 1] = i;
		pick(ball, ballSize, picked, pickSize, toPick - 1);
	}
}
int main(void)
{
	char ball[7] = { 'A','B','C','D','E','F','G' };
	int picked[3];

	pick(ball, 7, picked, 3, 3);
}