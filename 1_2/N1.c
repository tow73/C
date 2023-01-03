#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int addEach(int n) // 이 함수를 작성해서 제출
{
	int sum = 0;
	if (n == 0)
		return 0;
	else {
		sum = n % 10 + addEach(n / 10);
		return sum;
	}
}
int main(void) // 변경하지 말라
{
	int num;
	scanf("%d", &num);
	printf("%d\n", addEach(num));
}
