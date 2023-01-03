#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char num[81];
	int i;
	int n = 0;
	int sum = 0;

	printf("Enter a word: ");
	scanf("%s", num);

	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] >= '0' && num[i] <= '9') {
			n += num[i] - 48;
			if (num[i + 1] >= '0' && num[i + 1] <= '9')
				n *= 10;
			else {
				sum += n;
				n = 0;
			}
		}
	}
	printf("글자 안의 수의 합은 %d", sum);
}