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
	struct student* sp = s;

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", (*sp).name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &(*sp).mid, &(*sp).final);
		sp++;
	}
	sp = s;
	for (i = 0; i < 3; i++) {
		printf("이름	중간	학기말\n");
		printf("%s	%d	%d\n", (*sp).name, (*sp).mid, (*sp).final);  //(*sp).name 이런식으로 쓰기
		sp++;
	}
}