#define _CRT_SECURE_NO_WARNINGS
#include <Stdio.h>
void to_binary(int n);
int main(void)
{
	int num;
	scanf("%d", &num);
	to_binary(num);
}
void to_binary(int n)
{
	if (n == 0 || n ==1) {
		printf("%d ", n);
		return;
	}
	else {
		to_binary(n / 2);  //순서 바꿔보기
		printf("%d ", n % 2);
	}
}