#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int addEach(int n) // �� �Լ��� �ۼ��ؼ� ����
{
	int sum = 0;
	if (n == 0)
		return 0;
	else {
		sum = n % 10 + addEach(n / 10);
		return sum;
	}
}
int main(void) // �������� ����
{
	int num;
	scanf("%d", &num);
	printf("%d\n", addEach(num));
}
