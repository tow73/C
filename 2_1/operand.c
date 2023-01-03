#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char op[], int opSize, int* picked, int pickSize, int toPick)
{
	int i, smallest, lastIndex;
	int sum = 0;

	if (toPick == 0) {
		for (i = 0; i < pickSize; i++) {
			printf("%c%d", op[picked[i]], i + 1);

			if (op[picked[i]] == '+')
				sum += (i + 1);
			else if (op[picked[i]] == '-')
				sum += -(i + 1);
		}
		printf(" = %d", sum);
		printf("\n");

		return;
	}

	lastIndex = pickSize - toPick - 1;

	for (i = 0; i < opSize; i++) {
		picked[lastIndex + 1] = i;
		pick(op, opSize, picked, pickSize, toPick - 1);
	}
}
int main(void)
{
	char op[2] = { '+','-' };
	int num;

	printf("¼ýÀÚ: ");
	scanf("%d", &num);

	int picked = (int)malloc(sizeof(int) * num);

	pick(op, 2, picked, num, num);
}