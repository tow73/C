#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[5];
	printf("���ڿ��� �Է��ϼ���:");
	gets(str1);
	printf("�Է��� ���ڿ��� %s\n", str1);
	printf("���ڿ��� ũ��� %d\n", strlen(str1));
}