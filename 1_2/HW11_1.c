#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct student {
	char name[20];
	int midterm;
	int final;
	int average;
	char grade;
};
struct student s[3];
struct student* sp = s;
int main(void)
{
	int i;
	int m = 0;
	int f = 0;

	for (i = 0; i < 3; i++) {
		printf("Enter student name: ");
		scanf("%s", sp->name);
		printf("Enter midterm and final score: ");
		scanf("%d %d", &sp->midterm, &sp->final);
		sp++;
	}

	sp = s;
	for (i = 0; i < 3; i++) {
		sp->average = (sp->midterm + sp->final) / 2;  //���� for���̶� �� ���� ����
		sp++;
	}	

	printf("\n");
	sp = s;
	for (i = 0; i < 3; i++) {  //i++,sp++ �̷��� ���� �ᵵ ��
		printf("�̸�	�߰�	�б⸻	���\n");
		printf("%s	%d	%d	%d\n", sp->name, sp->midterm, sp->final, sp->average);
		sp++;
	}

	sp = s;
	for (i = 0; i < 3; i++) {
		if (sp->average >= 80)
			sp->grade = 'A';
		else if (sp->average >= 50)
			sp->grade = 'B';
		else
			sp->grade = 'F';
		sp++;
	}

	printf("\n");
	sp = s;
	for (i = 0; i < 3; i++) {  //���� for���̶� ���� �ᵵ �Ǵ��� Ȯ��
		printf("�̸�	����\n");
		printf("%s	%c\n", sp->name, sp->grade);
		sp++;
	}

	sp = s;
	for (i = 0; i < 3; i++) {
		m += sp->midterm;
		f += sp->final;
		sp++;
	}
	m = m / 3;
	f = f / 3;

	printf("\n");
	printf("�߰������ ��� = %d\n", m);
	printf("�⸻����� ��� = %d\n", f);
}