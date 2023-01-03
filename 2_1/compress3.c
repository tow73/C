#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void compress(char* s)
{
	int i, j, len, index;
	int min = 1000;
	char temp[1000] = "";
	char s1[1000], s2[1000], num[4];

	for (i = 1; i <= strlen(s) / 2; i++) {
		strncpy(s1, s, i);
		s1[i] = '\0';
		len = 1;
		for (j = i; j < strlen(s); j += i) {
			index = 0;
			while (i > index)
				s2[index++] = s[j + index];
			s2[index] = '\0';
			if (strcmp(s1, s2) == 0)
				len++;
			else {
				if (len > 1) {
					sprintf(num, "%d", len);
					strcat(temp, num);
				}
				strcat(temp, s1);

				strcpy(s1, s2);
				len = 1;
			}
		}
		if (len > 1) {
			sprintf(num, "%d", len);
			strcat(temp, num);
		}
		strcat(temp, s1);

		min = min <= strlen(temp) ? min : strlen(temp);
		temp[0] = '\0';
	}
	printf("%d\n", min);
}
int main(void)
{
	char s[1000];

	scanf("%s", s);

	compress(s);
}