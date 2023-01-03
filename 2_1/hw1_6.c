#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i;
	char answer;

	printf("*** 로또 번호 생성기 ***\n");

	do {
		srand(time(NULL));
		printf("생성 번호: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);
		printf("\n");

		printf("다시 생성하시겠습니까?(y/n) ");
		scanf("%c", &answer);

		while (getchar() != '\n');
	} while (answer != 'n');
}