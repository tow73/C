#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	srand(time(NULL));
	FILE* fp1, * fp2, * fp3;
	int n, num;
	int count = 0;
	int sum = 0;
	char ch;

	fp1 = fopen("random.txt", "at");  //wt�� ����..?
	while (count != 10) {
		n = rand() % 100;
		fprintf(fp1, "%d\n", n);
		count++;
	}
	fclose(fp1);
	
	fp2 = fopen("random.txt", "rt");
	fp3 = fopen("output.txt", "wt");
	fscanf(fp1, "%d", &n);
	while (!feof(fp1)) {
		printf("%d\t", n);
		fprintf(fp3, "%d\n", n);
		fscanf(fp1, "%d", &n);  //sum+=n�� �ڸ� �ٲٱ�(���ص� ���x)
		sum += n;
	}
	printf("\n���� %d\n", sum);
	fprintf(fp3, "���� %d\n", sum);
	fclose(fp2);
	fclose(fp3);
}