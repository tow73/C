#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum_rec(int n);
void main()
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("1���� %d������ ���� %d�Դϴ�,\n", n, sum_rec(n));
}
int sum_rec(int n)
{
	if (n == 1)
		return 1;
	else 
		return n + sum_rec(n - 1);
}