#include <stdio.h>
#include <stdlib.h>
void generateData();
void printData();
int totalData();
int maxData();
int data[10]; // 계산 수행에 사용할 전역 변수
int main(void)
{
	srand(200);
	generateData();
	printf("발생된 10개의 난수:\n");
	printData();
	printf("10개 난수의 합 = %d \n", totalData());
	printf("10개 난수중 가장 큰 수 = %d \n", maxData());
}
void generateData()
{
	int k;
	int* p; //= data
	p = data; //혹은 p = &data[0]
	for (k = 0; k < 10; k++) // Index 0..9까지 난수값 부여
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
		//pi++; 여기 써야 함
	return max;
}