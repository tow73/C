#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibo(int n);
int main(void)
{
	int n, idx;
	printf("몇개의 피보나치 수열값을 출력할까요?(3보다 큰 정수):");
	scanf("%d", &n);
	for (idx = 0; idx < n; idx++)
	{
		printf("%d ", fibo(idx));
		if ((idx + 1) % 5 == 0)
			printf("\n");
	}
	printf("\n");
}
int fibo(int n)
{
	int i, c;
	static int a = 1;
	static int b = 1;
	if (n == 0 || n == 1)
		return 1;
	else
		for (i = 2; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
			return c;
		}
		/*for (i = 0; i < n; i++)  //i = 2; i <= n 으로 해도 됨
		{
			c = a + b;
			a = b;
			b = c;
			return b;  //return c임
		}*/
}