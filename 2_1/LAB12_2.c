#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int distance, i, len;
	char alpha[27] = "";
	char encoding[27] = "";
	char ori[101] = "";
	char encoded[101] = "";
	FILE* fp1, * fp2;

	scanf("%d", &distance);

	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;
	printf("%s\n", alpha);
	for (i = 0; i < 26; i++) {
		encoding[i] = alpha[i] + distance;
		if (encoding[i] > 'Z')
			encoding[i] -= 26;
	}
	printf("%s\n\n", encoding);

	if ((fp1 = fopen("ori.txt", "rt")) == NULL) {
		printf("파일 오픈 에러1");
		exit(1);
	}
	if ((fp2 = fopen("encoded.txt", "wt")) == NULL) {
		printf("파일 오픈 에러2");
		exit(1);
	}
	while (fgets(ori, sizeof(ori), fp1) != NULL) {
		len = strlen(ori);
		for (i = 0; i < len; i++) {
			if (ori[i] >= 'A' && ori[i] <= 'Z') {
				int index = ori[i] - 'A';
				encoded[i] = encoding[index];
			}
			else
				encoded[i] = ori[i];
		}
		fputs(encoded, fp2);
		memset(ori, 0x00, sizeof(ori));
		memset(encoded, 0x00, sizeof(encoded));
	}
	
	fclose(fp1);
	fclose(fp2);
}