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

	fgets(buf, sizeof(buf), fp1); // �Է� ���Ͽ��� ���� �о
	while (!feof(fp1)) // ������ ���� �ƴϸ� ��� �ݺ�
	{
		fputs(buf, fp2); // ��� ���Ͽ� ���
		fgets(buf, sizeof(buf), fp1); // �Է� ���Ͽ��� �� �о(�ٽ�) ������ �б�
	}
	
	fclose(fp1);
	fclose(fp2);
}