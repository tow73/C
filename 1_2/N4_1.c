#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 20
typedef struct {
	char name[MAX];
	int mid;
	int final;
	char grade;
} Student;
void printStudent(Student* m) // �ۼ��ؼ� ����
{
	printf("%s %d %d %c\n", m->name, m->mid, m->final, m->grade);
}
void readNewStudent(Student* m, int* snPtr) // �ۼ��ؼ� ����
{
	int i = *snPtr;
	scanf("%s %d %d", m[i].name, &m[i].mid, &m[i].final);
	(*snPtr)++;
}
void calculateGrade(Student* m, int size) // �ۼ��ؼ� ����
{
	int i;
	for (i = 0; i < size; i++) {
		if (m[i].mid + m[i].final > 100)
			m[i].grade = 'A';
		else
			m[i].grade = 'F';
	}
}
int main(void) // �������� ����
{
	Student Students[MAX];
	int i;
	int StudentNum = 0;
	int choice;

	scanf("%d", &choice);
	while (choice != -1) {
		readNewStudent(Students, &StudentNum);
		scanf("%d", &choice);
	}
	calculateGrade(Students, StudentNum);
	for (i = 0; i < StudentNum; i++)
		printStudent(&Students[i]);
}
