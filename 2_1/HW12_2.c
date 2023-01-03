#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
void printCode(char alpha[], char code[], char plain[], int len)
{
	int i, j;
	char encode[101] = "";
	
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < 26; j++) {
			if (plain[i] == alpha[j]) {
				encode[i] = code[j];
				break;
			}
			else if (plain[i] == ' ') {
				encode[i] = ' ';
				break;
			}
		}
	}
	printf("%s", encode);
}
int main(void)
{
	char alpha[27] = "";
	char code[27] = "";
	char key[30];
	char plain[101] = "";
	int distance, i, len;

	scanf("%s", key);
	scanf("%d", &distance);

	for (i = 0; i < 26; i++)
		alpha[i] = 'A' + i;
	remove_duplicated_char(key, strlen(key));
	makeCode(alpha, code, distance, key, strlen(key));

	printf("%s\n", alpha);
	printf("%s\n", code);

	fgets(plain, 100, stdin); //newline char
	fgets(plain, 100, stdin); //키보드 입력
	printCode(alpha, code, plain, strlen(plain));
}