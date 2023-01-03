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
void calculateAll(CClass* cp, Student* pAll)
{
	int i;
	for (i = 0; i < cp->num; i++) {
		pAll->midterm += cp->s[i].midterm;
		pAll->final += cp->s[i].final;
		pAll->average += cp->s[i].average;
	}
	pAll->midterm /= cp->num;  //midterm≥¢∏Æ, final≥¢∏Æ, average≥¢∏Æ «ÿº≠ forπÆ 3∞≥ Ω·µµ µ 
	pAll->final /= cp->num;
	pAll->average /= cp->num;
}
void printStudent(Student* pAll)
{
	printf("%s\t%d\t%d\t%d\n", pAll->name, pAll->midterm, pAll->final, pAll->average);
}
int main(void)
{
	CClass cp;
	Student all = { "All", 0, 0, 0 };
	printf("Enter a number of student:");
	scanf("%d", &cp.num);
	readClass(&cp);
	calculateClassAverage(&cp);
	printf("\n ¿Ã∏ß\t ¡ﬂ∞£\t «–±‚∏ª\t ∆Ú±’\n");
	printClass(&cp);
	calculateAll(&cp, &all);
	printf("----------------------------------\n");
	printStudent(&all);
}