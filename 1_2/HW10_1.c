#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i;
	int m = 0;
	int f = 0;

	struct student {
		char name[20];
		int midterm;
		int final;
		int average;
		char grade;
	};
	struct student s[3];

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", s[i].name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &s[i].midterm, &s[i].final);
	}

	for (i = 0; i < 3; i++)
		s[i].average = (s[i].midterm + s[i].final) / 2;  //������ �ѹ���

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("�̸�	�߰�	�б⸻	���\n");  //���� ����
		printf("%s	%d	%d	%d\n", s[i].name, s[i].midterm, s[i].final, s[i].average);
	}

	for (i = 0; i < 3; i++) {
		if (s[i].average >= 80)
			s[i].grade = 'A';
		else if (s[i].average >= 50)
			s[i].grade = 'B';
		else
			s[i].grade = 'C';  //�̰� F��..
	}

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("�̸�	����\n");  //���� ���� ��..
		printf("%s	%c\n", s[i].name, s[i].grade);
	}

	for (i = 0; i < 3; i++) {
		m += s[i].midterm;
		f += s[i].final;
	}
	m = m / 3;
	f = f / 3;

	printf("\n");
	printf("�߰������ ��� = %d\n", m);
	printf("�⸻����� ��� = %d\n", f);
}