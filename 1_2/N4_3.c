#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef struct {
	char name[MAX];
	int mid;
	int final;
	char grade;
} Student;

typedef struct {
	int num;
	Student s[40];
} CClass;


// �ʿ��� �Լ����� ���Ǹ� �߰��ؼ� �̸� ����

int main(void) // �������� ����
{
	CClass cClass;

	cClass.num = 0; // �ʱ⿡�� �л��� 0

	readClass(&cClass);
	calculateClassGrade(&cClass); // ���� ���
	printClass(&cClass); // �л� ������ ���
}
