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
	max = -999;  //INT_MAX stdio.h에 저장되어 있음 -20?
	min = 999;  //INT_MIN stdio.h에 저장되어 있음 20?
	maxIndex = 0;  //0값 안 넣어줘도 될 듯
	minIndex = 0;  //0값 안 넣어줘도 될 듯
	for (i = 0; i < size; i++)
	{
		if (max < arr[i])  //=붙이기
		{
			max = arr[i];
			maxIndex = i;
		}			
		if (min > arr[i])  //=붙이기
		{
			min = arr[i];
			minIndex = i;
		}
	}
	printf("최대값: 인덱스 = %d, 값 = %d\n", maxIndex, max);
	printf("최소값: 인덱스 = %d, 값 = %d\n", minIndex, min);
}
int main(void)
{
	int a[10];
	//srand(time(NULL)); 
	srand(100); // 실행결과가 맞나 보기 위해서 seed를 100으로 고정
	initArray(a, 10);
	printArray(a, 10);
	printMinMax(a, 10);
	return 0;
}