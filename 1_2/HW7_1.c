#include <stdio.h>
#include <stdlib.h>
void generateData();
void printData();
int totalData();
int maxData();
int data[10]; // ��� ���࿡ ����� ���� ����
int main(void)
{
	srand(200);
	generateData();
	printf("�߻��� 10���� ����:\n");
	printData();
	printf("10�� ������ �� = %d \n", totalData());
	printf("10�� ������ ���� ū �� = %d \n", maxData());
}
void generateData()
{
	int k;
	int* p; //= data
	p = data; //Ȥ�� p = &data[0]
	for (k = 0; k < 10; k++) // Index 0..9���� ������ �ο�
		data[k] = rand() % 100;  //data[] = *p++
}
void printData()
{
	int* pi = data;
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", *pi++);
	printf("\n");
}
int totalData()
{
	int* pi = data, sum = 0;
	int i;
	for (i = 0; i < 10; i++)
		sum += *pi++;
	return sum;
}
int maxData()
{
	int* pi = data;
	int i, max = -999;
	for(i=0;i<10;i++)
		if (*pi > max) {
			max = *pi;
			pi++;
		}
		//pi++; ���� ��� ��
	return max;
}