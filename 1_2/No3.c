#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n)
{
	int rest, answer = 0;

	while (n > 0) {
		rest = n % 10;
		answer = answer * 10 + rest;
		n = n / 10;
	}

	return answer;
}
int main(void)
{
	int num;
	int count = 0;

	scanf("%d", &num);
	int rev = solution(num);

	while (num != rev) {
		num += rev;
		rev = solution(num);
		if (num < 0)
			break;
		count++;
	}
	if (num < 0)
		printf("Overflow\n");
	else
		printf("%d %d\n", count, num);
}