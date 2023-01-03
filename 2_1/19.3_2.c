#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n)
{
	int i = 0;
	while (n > 0) {
		n /= 10;
		i++;
	}
	return i;
}
int xPower(int x, int y)
{
	if (y == 1)
		return y;
	else if (y == 0)
		return 1;
	else
		return x * xPower(x, y - 1);
}
int main(void)
{
	int three[100000] = { 0 };
	int i = 0;
	int n = 1;
	int value, num, jarisu, ten;

	scanf("%d", &num);

	while (i < num) {
		value = n;
		if (n % 3 == 0) {
			jarisu = solution(value);
			ten = xPower(10, jarisu);
			while (value != -1) {
				three[i] = value / ten;
				value = value % ten;
				i++;

				if (ten == 1)
					value = -1;
				if (i == num)
					break;

				jarisu--;
				ten /= 10;
			}
		}
		n++;
	}

	printf("%d", three[num - 1]);
}