#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int same(int n1[5], int n2[5])
{
	int i;

	for (i = 0; i < 5; i++)
		if (n1[i] != n2[i])
			return 0;
	return 1;
}
int main(void)
{
	int num1[5], num2[5];
	int i;
	
	printf("Enter 첫번째 배열: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &num1[i]);
	printf("Enter 두번째 배열: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &num2[i]);

	if (same(num1, num2))
		printf("두 개의 배열은 같다");
	else
		printf("두 개의 배열은 다르다");
}