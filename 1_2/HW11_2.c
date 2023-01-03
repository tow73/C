#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;
struct cClass {
	int num;
	Student s[40];
};
typedef struct cClass CClass;
void printClass(CClass* cp)
{
	int i;
	for (i = 0; i < cp->num; i++) {
		printf("%s\t", cp->s[i].name);
		printf("%d\t%d\t%d\n", cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
	}
}
void readClass(CClass* cp)
{
	int i;
	for (i = 0; i < cp->num; i++) {
		printf("Enter student name: ");
		scanf("%s", cp->s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &cp->s[i].midterm, &cp->s[i].final);
	}
}
void calculateClassAverage(CClass* cp)
{
	int i;
	for (i = 0; i < cp->num; i++)
		cp->s[i].average = (cp->s[i].midterm + cp->s[i].final) / 2;
}
int main(void)
{
	CClass cp;
	Student all = { "Total", 0, 0, 0 };
	printf("Enter a number of student:");
	scanf("%d", &cp.num);
	readClass(&cp); // 앞 코드의 a)부분 대치
	calculateClassAverage(&cp); // 앞 코드의 b)부분 대치
	printf("\n이름\t중간\t학기말\t평균\n");
	printClass(&cp);
}