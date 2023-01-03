#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isPrime(int x)
{
	int i;

	for (i = 2; i < x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}
int main(void)
{
	int i;
	int n = 2;
	for (i = 2; i < 31; i++) {
		if (isPrime(n))
			printf("%d ", n);
		n++;
	}
	
}