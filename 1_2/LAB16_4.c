#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int test[4][3] = { {8, 7}, {6, 5}, {1, 2}, {3, 4} };
	int i, j;
	int total = 0;
	double average = 0;
	int max = -999;

	printf("배열 test의 엘리먼트를 출력합니다\n");
	for (i = 0; i < 4; i++)
	{ 
		printf("\n%d번째 row: ", i + 1);
		for (j = 0; j < 3; j++)
			printf("%d ", test[i][j]);
	}
	printf("\n");  //두 번째 for문 끝난 후에 써도 됨

	printf("\n다>\n");
	printf("배열 test의 엘리먼트를 출력합니다\n");
	for (i = 0; i < 4; i++)  //밑의 for문과 합칠 수도 있음
		test[i][2] = -1;
	for (i = 0; i < 4; i++)
	{
		printf("\n%d번째 row: ", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("%d ", test[i][j]);
			total += test[i][j];
		}			
	}
	average = (double)total / 12;  //12.0쓰면 (double) 없어도 됨
	printf("\n");

	printf("\n라>\n");
	printf("Total is %d\n", total);
	printf("Average is %.2f\n", average);
	printf("\n");

	printf("마>\n");
	total = 0;
	for (i = 0; i < 4; i++)
	{
		printf("\n%d번째 row에서의 최대값: ", i + 1);
		for (j = 0; j < 3; j++)
			if (test[i][j] > max)
				max = test[i][j];
		total += max;
		printf("%d", max);
		max = 0;
	}
	printf("\n");
	printf("최대값의 합: %d\n", total);
}