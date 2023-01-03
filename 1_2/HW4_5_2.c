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
	printf("%d ", n);
	if (n == 1)
		return + 1;  //그냥 1을 return해도 되는 듯
	else
		if (n % 2 == 0)
			return get_cycle_number(n / 2) + 1;
		else
			return get_cycle_number(n * 3 + 1) + 1;
}