#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int k[5][3] = {0};
	int n[5][3];
	int i, j;
	int total = 0;

	printf("��>\n");
	for (i = 0; i < 5; i++)
		for (j = 0; j < 3; j++)
		{
			printf("%d ", k[i][j]);

			if (j == 2)  // �ʿ� ���� �� ���� ���� �ٹٲ� �ϵ��� �����
				printf("\n");
		}
	printf("��>\n");
	for (i = 0; i < 5; i++)  // total �κ� ��ø while�� ���⿴��..��
		for (j = 0; j < 3; j++)
		{
			n[i][j] = i + j;  // �̰� for�� ����
			total += n[i][j];
			printf("%d ", n[i][j]);

			if (j == 2)  // �ʿ� ���� �� ���� ���� �ٹٲ� �ϵ��� �����
				printf("\n");
		}
	printf("��>\n");
	printf("Total is %d", total);
}