#include <stdio.h>
#include <string.h>
int main(void)
{
	char str2[5];
	printf("���ڿ��� �Է��ϼ���:");
	fgets(str2, sizeof(str2), stdin);
	printf("�Է��� ���ڿ��� %s\n", str2);
	printf("���ڿ��� ũ��� %d\n", strlen(str2));
}