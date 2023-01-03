#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void multiple(char n[])
{
	int len = strlen(n);
	long long i;
	long long sum = 0;
	int f = 0;

	/*for (i = 0; i < strlen(n); i++) // 각 자리 수의 합
		sum = sum + n[i] - '0';
	if (strlen(n) > 2)  //100으로 나눈 나머지
		n = (n[strlen(n) - 2] - '0') * 10;
	else  //없어도 됨
		n = n + n[strlen(n) - 1] - '0';*/

	if ((n[len - 1] - 48) % 2 == 0)
		printf("1");
	else
		printf("0");

	for (i = len - 1; i >= 0; i--)
		sum += (int)n[i] - 48;
	if (sum % 3 == 0)
		printf("1");
	else
		printf("0");

	if (len >= 2) {
		f += (int)n[len - 2] - 48;
		f *= 10;
		f += (int)n[len - 1] - 48;
	}
	else
		f = atoi(n);
	if (f % 4 == 0)
		printf("1");
	else
		printf("0");

	if ((n[len - 1] - 48) % 5 == 0)
		printf("1");
	else
		printf("0");
}
int main(void)
{
	char num[51];

	scanf("%s", num);
	multiple(num);
}