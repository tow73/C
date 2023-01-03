#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void remove_duplicated_char(char* word, int len)
{
	int i, j, k, flag;

	for (i = 0; i < len; i++) {
		flag = 1;
		for (j = 0; j < len; j++)
			if (i != j && word[i] == word[j]) {
				flag = 0;
				break;
			}
		if (flag == 0) {
			for (k = j; k < len; k++)
				word[k] = word[k + 1];
			len--;
		}
	}
}
void makeCode(char alpha[], char code[], int distance, char* key, int len)
{
	int i, k, flag;
	int j = 0;
	//int nonskip = 0;
	//int skip = distance + len;
	char alpha2[27] = "";
	int len2 = 26;

	for (i = 0; i < 26; i++)
		alpha2[i] = alpha[i];
	for (i = distance; i < len + distance; i++) {
		code[i] = key[j];
		j++;
	}
	for (i = 0; i < 26; i++) {
		flag = 1;
		for (j = 0; j < len; j++)
			if (alpha2[i] == key[j]) {
				flag = 0;
				break;
			}
		if (flag == 0) {
			for (k = i; k < len2; k++)
				alpha2[k] = alpha2[k + 1];
			len2--;
			i--;
		}
	}
	j = 0;
	for (i = len + distance; i < 26; i++) {
		code[i] = alpha2[j];
		j++;
	}
	for (i = 0; i < distance; i++) {
		code[i] = alpha2[j];
		j++;
	}
	/*for (i = 0; i < 26; i++) {
		flag = 1;
		for (j = 0; j < len; j++)
			if (key[j] == alpha[i]) {
				flag = 0;
				break;
			}
		if (flag == 1 && skip < 26) {
			code[skip] = alpha[i];
			skip++;
		}
		else if (flag == 1 && skip >= 26) {
			code[nonskip] = alpha[i];
			nonskip++;
		}
	}*/
}
int main(void)
{
	char alpha[27] = "";
	char code[27] = "";
	char key[30];
	char plain[101] = "";
	char encode[101] = "";
	int distance, i, j, len;
	FILE* fp1, * fp2;

	scanf("%s", key);
	scanf("%d", &distance);

	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;
	remove_duplicated_char(key, strlen(key));
	makeCode(alpha, code, distance, key, strlen(key));
	printf("%s\n", alpha);
	printf("%s\n", code);

	if ((fp1 = fopen("in.txt", "rt")) == NULL) {
		printf("파일 오픈 에러1");
		exit(1);
	}
	if ((fp2 = fopen("out.txt", "wt")) == NULL) {
		printf("파일 오픈 에러2");
		exit(1);
	}
	while (fgets(plain, sizeof(plain), fp1) != NULL) {
		len = strlen(plain);
		for (i = 0; i < len; i++) {
			for (j = 0; j < 26; j++) {
				if (plain[i] >= 'A' && plain[i] <= 'Z') {
					if (plain[i] == alpha[j]) {
						encode[i] = code[j];
						break;
					}
				}
				else
					encode[i] = plain[i];
			}
		}
		fputs(encode, fp2);
		memset(plain, 0x00, sizeof(plain));
		memset(encode, 0x00, sizeof(encode));
	}

	fclose(fp1);
	fclose(fp2);
}