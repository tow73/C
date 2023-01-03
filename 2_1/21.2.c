#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num, n, i, j;
	int count = 0;
	int ten;

	scanf("%d", &num);

	num *= 9;
	n = num;

	while (num != 0) {
		num /= 10;
		count++;
	}
	while (count != 0) {
		ten = 1;
		for (i = count - 1; i > 0; i--)
			ten *= 10;
		printf("%d ", n / ten);
		n %= ten;
		count--;
	}
}