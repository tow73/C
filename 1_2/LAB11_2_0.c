#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;
void printStudent(Student *aStudent)
{
	printf("%s\t", aStudent->name);
	printf("%d\t%d\t%d\n", aStudent->midterm, aStudent->final, aStudent->average);
}
int main(void)
{
	Student s[40];
	struct student* st = s;
	int num, i;
	printf("Enter a number of student:");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("Enter student name: "); //a)
		scanf("%s", s[i].name); //b)
		printf("Enter midterm and final score: "); //c)
		scanf("%d %d", &s[i].midterm, &s[i].final); //d)
	}
	for (i = 0; i < num; i++)
		s[i].average = (s[i].midterm + s[i].final) / 2; //) e
	printf("\n 이름\t 중간\t 학기말\t 평균\n");
	for (i = 0; i < num; i++) {
		printStudent(st);  //&s[i]로 써도 됨
		st++;
	}
}