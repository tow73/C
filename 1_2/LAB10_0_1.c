#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i;

	struct student {
		char name[20];
		int mid;
		int final;
	};
	struct student s[3];

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &s[i].mid, &s[i].final);
	}

	for (i = 0; i < 3; i++) {
		printf("이름	중간	학기말\n");
		printf("%s	%d	%d\n", s[i].name, s[i].mid, s[i].final);
	}
}