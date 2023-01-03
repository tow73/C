#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
int main(void)
{
	FILE* fp1, * fp2;  //getc, putc »ç¿ë
	char ch;

	fp1 = fopen("input.txt", "rt");
	if (fp1 == NULL) {
		printf("file open error!\n");
		return 1;
	}
	fp2 = fopen("output.txt", "wt");
	if (fp2 == NULL) {
		printf("file open error!\n");
		return 1;
	}

	ch = fgetc(fp1);
	while (!feof(fp1))
	{
		fputc(toupper(ch), fp2);
		ch = fgetc(fp1);
	}
	fprintf(fp2, "\n");

	fseek(fp1, 0, SEEK_SET);
	ch = fgetc(fp1);
	while (!feof(fp1))
	{
		fputc(tolower(ch), fp2);
		ch = fgetc(fp1);
	}
	fclose(fp2);
}