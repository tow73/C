#define _CRT_SEUCRE_NO_WARNINGS
#include <stdio.h>
int comb(int n, int r)
{
	if (r == 0 || n == r)
		return 1;
	else
		return  comb(n - 1, r - 1) + comb(n - 1, r);
}
int main(void)
{
	int C10_5;

	C10_5 = comb(10, 5);
	printf("%d\n", C10_5);
	return 0;
}