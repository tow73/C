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
void printClass(CClass* cp)
{
	int i;
	for (i = 0; i < cp->num; i++) {
		printf("%s\t", cp->s[i].name);
		printf("%d\t%d\t%d\n", cp->s[i].midterm, cp->s[i].final, cp->s[i].average);
	}
}
Student calculateAll2(CClass* cp)
{
	Student pAll = { "All", 0, 0, 0 };
	int i;
	for (i = 0; i < cp->num; i++) {
		pAll.midterm += cp->s[i].midterm;
		pAll.final += cp->s[i].final;
		pAll.average += cp->s[i].average;
	}
	pAll.midterm /= cp->num;
	pAll.final /= cp->num;
	pAll.average /= cp->num;
	return pAll;
}
void printStudent(Student* pAll)
{
	printf("%s\t%d\t%d\t%d\n", pAll->name, pAll->midterm, pAll->final, pAll->average);
}
int main(void)
{
	CClass cp;
	Student all = { "All", 0, 0, 0 };  //이 문장 없애기
	printf("Enter a number of student:");
	scanf("%d", &cp.num);
	readClass(&cp);
	calculateClassAverage(&cp);
	printf("\n 이름\t 중간\t 학기말\t 평균\n");
	printClass(&cp);
	printf("----------------------------------\n");
	all = calculateAll2(&cp);
	printStudent(&all);
}