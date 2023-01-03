#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse_string(char* str, int s, int e)
{
	int i, temp;

	for (i = s; i <= e; i++) {
		temp = str[i];
		str[i] = str[e];
		str[e] = temp;
		e--;
	}
}
int main()
{
	char str[100];

	printf("Enter any string: ");
	scanf("%s", str);

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}