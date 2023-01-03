#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse(char src_s[], char s[])
{
	int i, len;

	len = strlen(src_s);
	for (i = len - 1; i >= 0; i--)
		s[len - i - 1] = src_s[i];
	s[len] = '\0';
}
int main(void)
{
	char src_s[101];
	char s[101];
	scanf("%s", src_s);
	reverse(src_s, s);
	printf("%s\n", s);
}