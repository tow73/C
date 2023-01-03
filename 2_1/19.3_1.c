#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n) // 코드 작성
{
	int i = 0;
	while (n > 0) {
		n /= 10;
		i++;
	}
	return i;
}
int main(void) // 변경하지 말라
{
	int n;
	int jarisu;

	scanf("%d", &n);

	jarisu = solution(n);
	printf("%d\n", jarisu);
	printf("%d\n", jarisu / 10);
}