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
		ss->average = (ss->midterm + ss->final) / 2; //) e  //for�� ���� �׳� �ص� ��
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
	readStudentScore(&s, num);  //for�� ����ؼ� �ϱ� &s[i]
	calculateStudentAverage(&s, num);  //for�� ����ؼ� �ϱ� &s[i]
	printf("\n �̸�\t �߰�\t �б⸻\t ���\n");
	for (i = 0; i < num; i++) {
		printStudent(st);  //for�� ����ؼ� �ϱ� &s[i]
		st++;
	}
}