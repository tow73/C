#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n);
int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);
	printf("\ncount: %d\n", get_cycle_number(num));

	return 0;
}
int get_cycle_number(int n)
{
	static int count = 1;

	printf("%d ", n);
	if (n == 1)  //while(n > 1)으로 사용 가능
		return count;
	else
	{
		if (n % 2 == 0)
		{
			count++;
			return get_cycle_number(n / 2);
		}
		else
		{
			count++;
			return get_cycle_number(n * 3 + 1);
		}
	}
}