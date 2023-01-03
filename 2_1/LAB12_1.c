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

	fgets(ori, 100, stdin); //newline char
	fgets(ori, 100, stdin); //키보드 입력
	len = strlen(ori);
	for (i = 0; i < len; i++) {
		if (ori[i] >= 'A' && ori[i] <= 'Z') {
			int index = ori[i] - 'A';
			encoded[i] = encoding[index];
		}
		else
			encoded[i] = ori[i];
	}
	//printf("%s", ori);
	printf("%s", encoded);
}