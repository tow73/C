#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	FILE* fp;

	fp = fopen("hello.txt", "at");
	if (fp == NULL) {
		printf("���� ���� �����Դϴ�!!!\n");
		return 1;
	}
	fprintf(fp, "Hi\n");
	fprintf(fp, "Everydody\n");
	fclose(fp);
}