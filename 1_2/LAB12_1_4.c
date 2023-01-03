#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	FILE* fp;
	char ch;

	fp = fopen("HW.out", "wt");
	if (fp == NULL) {
		printf("file open error!\n");
		return 1;
	}
	fprintf(fp, "Hello\n");
	fprintf(fp, "World\n");
	fclose(fp);

	fp = fopen("HW.out", "rt");
	if (fp == NULL) {
		printf("파일 오픈 에러입니다!!!\n");
		return 1;
	}
	ch = getc(fp);
	while (!feof(fp))
	{
		putc(ch, stdout);
		ch = getc(fp);
	}
	fclose(fp);
}