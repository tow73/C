#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int i;
	char answer;

	printf("*** �ζ� ��ȣ ������ ***\n");

	do {
		srand(time(NULL));
		printf("���� ��ȣ: ");
		for (i = 0; i < 6; i++)
			printf("%d ", rand() % 45 + 1);
		printf("\n");

		printf("�ٽ� �����Ͻðڽ��ϱ�?(y/n) ");
		scanf("%c", &answer);

		while (getchar() != '\n');
	} while (answer != 'n');
}