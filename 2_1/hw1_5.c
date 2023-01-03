#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char str[81] = { 0 };
	char key;
	int i;
	int count = 0;

	printf("Enter a String: ");
	scanf("%s", str);
	while (getchar() != '\n');
	printf("Enter a character: ");
	scanf("%c", &key);


	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == key)
			count++;

	printf("'%c' is appeared %d times\n", key, count);
}