#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int test[4][3] = { {8, 7}, {6, 5}, {1, 2}, {3, 4} };
	int i, j;
	int total = 0;
	double average = 0;
	int max = -999;

	printf("�迭 test�� ������Ʈ�� ����մϴ�\n");
	for (i = 0; i < 4; i++)
	{ 
		printf("\n%d��° row: ", i + 1);
		for (j = 0; j < 3; j++)
			printf("%d ", test[i][j]);
	}
	printf("\n");  //�� ��° for�� ���� �Ŀ� �ᵵ ��

	printf("\n��>\n");
	printf("�迭 test�� ������Ʈ�� ����մϴ�\n");
	for (i = 0; i < 4; i++)  //���� for���� ��ĥ ���� ����
		test[i][2] = -1;
	for (i = 0; i < 4; i++)
	{
		printf("\n%d��° row: ", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("%d ", test[i][j]);
			total += test[i][j];
		}			
	}
	average = (double)total / 12;  //12.0���� (double) ��� ��
	printf("\n");

	printf("\n��>\n");
	printf("Total is %d\n", total);
	printf("Average is %.2f\n", average);
	printf("\n");

	printf("��>\n");
	total = 0;
	for (i = 0; i < 4; i++)
	{
		printf("\n%d��° row������ �ִ밪: ", i + 1);
		for (j = 0; j < 3; j++)
			if (test[i][j] > max)
				max = test[i][j];
		total += max;
		printf("%d", max);
		max = 0;
	}
	printf("\n");
	printf("�ִ밪�� ��: %d\n", total);
}