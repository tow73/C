#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void compress(char* s)
{
	int i, j, len, index;
	int min = 1000;
	char temp[1000] = "";
	char s1[1000], s2[1000], num[4];

	strncpy(s1, s, 2);
	s1[2] = '\0';
	len = 1;
	for (j = 2; j < strlen(s); j += 2) {
		index = 0;
		while (2 > index)
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

	printf("%s\n%d\n", temp, strlen(temp));
}
int main(void)
{
	char s[1000];

	scanf("%s", s);

	compress(s);
}