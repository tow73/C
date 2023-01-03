#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	struct student {
		char name[20];
		int mid;
		int final;
	};
	struct student aStudent;
	struct student* sp = &aStudent;

	printf("Enter student name: ");
	scanf("%s", (*sp).name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &(*sp).mid, &(*sp).final);

	printf("이름	중간	학기말\n");
	printf("%s	%d	%d\n", (*sp).name, (*sp).mid, (*sp).final);
}