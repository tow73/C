#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int k_bonacci(int k, int n)
{
	int i;
	int total = 0;

	if (k >= n)
		return 1;
	else {
		for (i = n - 1; i >= n - k; i--)
			total += k_bonacci(k, i);

		return total;
	}
}
int main(void)
{
	int k, n;

	scanf("%d %d", &k, &n);

	printf("%d\n", k_bonacci(k, n));
}