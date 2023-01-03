#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	int count = 1;

	printf("%d ", n);

	while (n != 1)
	{
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;

		printf("%d ", n);

		count++;
	}

	return count;
}
int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);

	printf("\n±Ê¿Ã: %d\n", get_cycle_number(num));
}