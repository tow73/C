#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <time.h>
#include <stdio.h> 
void initArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		arr[i] = rand() % 100;
	return;
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void printMinMax(int arr[], int size)
{
	int i, max, min;
	int maxIndex, minIndex;
	max = -999;  //INT_MAX stdio.h�� ����Ǿ� ���� -20?
	min = 999;  //INT_MIN stdio.h�� ����Ǿ� ���� 20?
	maxIndex = 0;  //0�� �� �־��൵ �� ��
	minIndex = 0;  //0�� �� �־��൵ �� ��
	for (i = 0; i < size; i++)
	{
		if (max < arr[i])  //=���̱�
		{
			max = arr[i];
			maxIndex = i;
		}			
		if (min > arr[i])  //=���̱�
		{
			min = arr[i];
			minIndex = i;
		}
	}
	printf("�ִ밪: �ε��� = %d, �� = %d\n", maxIndex, max);
	printf("�ּҰ�: �ε��� = %d, �� = %d\n", minIndex, min);
}
int main(void)
{
	int a[10];
	//srand(time(NULL)); 
	srand(100); // �������� �³� ���� ���ؼ� seed�� 100���� ����
	initArray(a, 10);
	printArray(a, 10);
	printMinMax(a, 10);
	return 0;
}