#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int solution(int n) // �ڵ� �ۼ�
{
	int i = 0;
	while (n > 0) {
		n /= 10;
		i++;
	}
	return i;
}
int main(void) // �������� ����
{
	int n;
	int jarisu;

	scanf("%d", &n);

	jarisu = solution(n);
	printf("%d\n", jarisu);
	printf("%d\n", jarisu / 10);
}