#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int xPoswer(int x, int y);
int main(void)
{
	int x, y;
	printf("Enter two numbers: ");
	scanf("%d %d", &x, &y);
	printf("%d�� %d���� %d�̴�\n", x, y, xPower(x, y));
}
int xPower(int x, int y)
{
	if (y == 0)
		return 1;
	else
		return x * xPower(x, y - 1);
}