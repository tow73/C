#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
int main(void)
{
	FILE* fp1, * fp2;
	char buf[30];

	fp1 = fopen("hello.txt", "rt");
	if (fp1 == NULL) {
		printf("file open error!\n");
		return 1;
	}
	fp2 = fopen("hello2.txt", "wt");
	if (fp2 == NULL) {
		printf("file open error!\n");
		return 1;
	}

	fgets(buf, sizeof(buf), fp1);
	while (!feof(fp1)) {
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}

	fseek(fp1, 0, SEEK_SET);  //�ڵ����� a-���� ��, w-���� ó��
	fgets(buf, sizeof(buf), fp1);
	while (!feof(fp1)) {
		fputs(buf, fp2);
		fgets(buf, sizeof(buf), fp1);
	}

	fclose(fp1);
	fclose(fp2);
}