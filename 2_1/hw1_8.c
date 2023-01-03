#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char input(char n[81])
{
	scanf("%s", n);

	return n;
}
void reverse(char n[81])
{
	int i;
	int count = 0;
	
	for (i = 0; n[i] != '\0'; i++)
		count++;
	printf("Reverse name: ");
	for (i = count; i > -1; i--)
		printf("%c", n[i]);
}
int main(void)
{
	char name[81] = { 0 };

	printf("Enter the name: ");
	input(name);
	reverse(name);
}