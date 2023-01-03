#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int total(int n)
{
	int i;
	int total = 0;

	for (i = n; i > 0; i--)
		total += i;

	return total;
}
int main(void)
{
	int num;

	printf("Input a number: ");
	scanf("%d", &num);

	while (num != -1) {
		printf("1부터 %d까지의 합은 %d\n", num, total(num));

		printf("Input a number: ");
		scanf("%d", &num);
	}
}