#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int list[20] = { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100 };
int sorted_seq_search(int key, int low, int high)
{
	int i;
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;
	return -1;
}
int main(void)
{
	int num, re;

	printf("Enter a number(0~100): ");
	scanf("%d", &num);

	re = sorted_seq_search(num, list[0], list[19]);
	if (re == -1)
		printf("There is no number");
	else
		printf("There is a number '%d'", num);
}