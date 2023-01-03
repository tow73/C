#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int echo(int n[5])
{
	int i;

	for (i = 0; i < 5; i++)
		scanf("%d", &n[i]);

	return n;
}
void reverse(int n[5])
{
	int i;
	for (i = 4; i > -1; i--)
		printf("%d ", n[i]);
}
int main(void)
{
	int num[5] = {0};
	int i;

	printf("Enter five numbers: ");
	echo(num);

	printf("Print numbers: ");
	for (i = 0; i < 5; i++)
		printf("%d ", num[i]);
	printf("\n");
	printf("Reverse numbers: ");
	reverse(num);
}