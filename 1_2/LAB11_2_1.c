#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
};
typedef struct student Student;
void printStudent(Student* aStudent)
{
	printf("%s\t", aStudent->name);
	printf("%d\t%d\t%d\n", aStudent->midterm, aStudent->final, aStudent->average);
}
void readStudentScore(Student *ss, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("Enter student name: "); //a)
		scanf("%s", ss->name); //b)
		printf("Enter midterm and final score: "); //c)
		scanf("%d %d", &ss->midterm, &ss->final); //d)
		ss++;
	}
}
calculateStudentAverage(Student *ss, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		ss->average = (ss->midterm + ss->final) / 2; //) e  //for문 없이 그냥 해도 됨
		ss++;
	}		
}
int main(void)
{
	Student s[40];
	struct student* st = s;
	int num, i;
	printf("Enter a number of student:");
	scanf("%d", &num);
	readStudentScore(&s, num);  //for문 사용해서 하기 &s[i]
	calculateStudentAverage(&s, num);  //for문 사용해서 하기 &s[i]
	printf("\n 이름\t 중간\t 학기말\t 평균\n");
	for (i = 0; i < num; i++) {
		printStudent(st);  //for문 사용해서 하기 &s[i]
		st++;
	}
}