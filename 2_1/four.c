#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char four[], int fourSize, int* picked, int pickSize, int toPick)
{
	int i, j, smallest, lastIndex;

	if (toPick == 0) {
		for (i = 0; i < pickSize; i++)
			printf("%d ", picked[i]);
		printf("\n");

		return;
	}

	lastIndex = pickSize - toPick - 1;

	for (i = 0; i < fourSize; i++) {
		picked[lastIndex + 1] = i;
		pick(four, fourSize, picked, pickSize, toPick - 1);
	}
}
int main(void)
{
	int four[4] = { 0,1,2,3 };
	int picked[3];

	pick(four, 4, picked, 3, 3);
}