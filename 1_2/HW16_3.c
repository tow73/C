#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int gradeTable[5][4] = { {10, 15, 20, 0}, {30, 35, 20, 0}, {60, 65, 20, 0}, {90, 95, 20, 0}, {0, 0, 0, 0} };  //따지고보면 scoreTable
	int i, j;
	int sum1 = 0;
	int sum2 = 0;

	printf("a)\n");
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%4d", gradeTable[i][j]);
		printf("\n");  //얘는 잘 했는데..왜지..
	}
	printf("b)\n");
	for (i = 0; i < 5; i++)  //i < 4 이어야 함
	{  //sum = 0을 여기에
		for (j = 0; j < 3; j++)
		{
			sum1 += gradeTable[i][j];
			gradeTable[i][3] = sum1;  //이 문장을 두번째 for문 후에 그러면 보기 쉬울 듯?
		}
		sum1 = 0;
	}
	for (j = 0; j < 4; j++)  //j < 3 이어야 함
	{
		for (i = 0; i < 4; i++)
		{
			sum2 += gradeTable[i][j];
			gradeTable[4][j] = sum2;
		}
		sum2 = 0;
	}
	gradeTable[4][3] = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%4d", gradeTable[i][j]);
		printf("\n");
	}
}