#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_OF_MEMBERS 15 // sns �������� ��
// �Լ� ����
void print_links(int data[][NUM_OF_MEMBERS]);
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS]);
int main(void)
{
	int link_data[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 }; //���� link matrix 1���� matrix
	int link_result[NUM_OF_MEMBERS][NUM_OF_MEMBERS] = { 0 }; //2�̱����� ���谡 ǥ�õ� matrix
	int i = 0;
	int j = 0;
	int num_of_steps = 0;
	int ALL_ONES = 0;
	srand(100); // ���� ����� ������ؼ� �ϴ� ���带 100���� ����(���߿��� �ּ�ó���ؼ� ����)
   // srand( (unsigned int)time(NULL) );
	// link_data �� �ֱ�: �ڽ��� ��� 1���̴�
	for (i = 0; i < NUM_OF_MEMBERS; i++)
	{
		link_data[i][i] = 1; //i�� i�� ����� 1��. �� 1�� ǥ��.
	}
	// link_data �� �ֱ�: random�ϰ� ���� �߻����Ѽ� 1�� ģ���� �����Ѵ�.
	for (i = 0; i < NUM_OF_MEMBERS; i++) //�� user���� �뷫 4���� ģ���� �ִٰ� ����.
	{
		j = 0;
		while (j < 2) //i�� �� ���� ��ũ�� �����ϰ� i�� �ƴ� �ٸ� user�� i�� ����
		{
			int new_link = rand() % NUM_OF_MEMBERS;
			if (new_link != i)
			{
				link_data[i][new_link] = 1; //i�� new_link�� 1���̸�
				link_data[new_link][i] = 1; //new_linke�� i�� 1��.
				j++;
			}
		}
	}
	printf("=================================================================\n");
	printf("Friends matrix\n");
	printf("=================================================================\n");
	print_links(link_data); //���� 1�� ���� ���
	matrix_multiplication(link_data, link_result);
	printf("=================================================================\n");
	printf("Friends of friends matrix\n");
	printf("=================================================================\n");
	print_links(link_result); // ���� 2�̱����� ���� ���
}
void print_links(int data[][NUM_OF_MEMBERS])
{
	int i, j;
	for (i = 0; i < NUM_OF_MEMBERS; i++) {
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
}
void matrix_multiplication(int data[][NUM_OF_MEMBERS], int result[][NUM_OF_MEMBERS])
{
	int i, j, k;
	for(i = 0; i < NUM_OF_MEMBERS; i++)
		for (j = 0; j < NUM_OF_MEMBERS; j++)
			for (k = 0; k < NUM_OF_MEMBERS; k++) {
				result[i][j] += data[i][k] * data[k][j];
				if (result[i][j] == 1)
					break;
			}
}