#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void pick(char award[][7], int awardSize, int* picked, int pickSize, int toPick)
{
	int i, j, lastIndex, flag;

	if (toPick == 0) {
		for (i = 0; i < pickSize; i++)
			printf("%10s ", award[picked[i]]);
		printf("\n");

		return;
	}

	lastIndex = pickSize - toPick - 1;

	for (i = 0; i < awardSize; i++) {
		flag = 0;
		for (j = 0; j <= lastIndex; j++)
			if (picked[j] == i)
				flag = 1;
		if (!flag) {
			picked[lastIndex + 1] = i;
			pick(award, awardSize, picked, pickSize, toPick - 1);
		}
	}
}
int main(void)
{
	char award[][7] = { "����", "�����", "���߱�", "����", "����" };
	int num, i;

	printf("���� ������? ");
	scanf("%d", &num);

	int picked = (int)malloc(sizeof(int) * num);

	for (i = 0; i < num; i++)
		printf("\t��%d", (i + 1));
	printf("\n");

	pick(award, 5, picked, num, num);
}