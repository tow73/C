#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int result = 0;
void pick(char op[], int opSize, int* picked, int pickSize, int toPick, int k)
{
	int i, smallest, lastIndex;
	int sum = 0;

	if (toPick == 0) {
		for (i = 0; i < pickSize; i++) {
			if (op[picked[i]] == '+')
				sum += (i + 1);
			else if (op[picked[i]] == '-')
				sum += -(i + 1);
		}
		if (sum == k)
			result = 1;

		return;
	}

	lastIndex = pickSize - toPick - 1;

	for (i = 0; i < opSize; i++) {
		picked[lastIndex + 1] = i;
		pick(op, opSize, picked, pickSize, toPick - 1, k);
	}
}
int main(void)
{
	char op[2] = { '+','-' };
	int num, key;

	scanf("%d %d", &num, &key);

	int picked = (int)malloc(sizeof(int) * num);

	pick(op, 2, picked, num, num, key);

	if (result == 1)
		printf("1");
	else
		printf("0");
}