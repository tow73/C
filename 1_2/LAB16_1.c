#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int k[5][3] = {0};
	int n[5][3];
	int i, j;
	int total = 0;

	printf("가>\n");
	for (i = 0; i < 5; i++)
		for (j = 0; j < 3; j++)
		{
			printf("%d ", k[i][j]);

			if (j == 2)  // 필요 없음 한 바퀴 돌면 줄바꿈 하도록 만들기
				printf("\n");
		}
	printf("나>\n");
	for (i = 0; i < 5; i++)  // total 부분 중첩 while문 쓰기였음..ㅎ
		for (j = 0; j < 3; j++)
		{
			n[i][j] = i + j;  // 이건 for문 쓰기
			total += n[i][j];
			printf("%d ", n[i][j]);

			if (j == 2)  // 필요 없음 한 바퀴 돌면 줄바꿈 하도록 만들기
				printf("\n");
		}
	printf("다>\n");
	printf("Total is %d", total);
}