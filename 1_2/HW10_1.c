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
		s[i].average = (s[i].midterm + s[i].final) / 2;  //위에랑 한번에

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("이름	중간	학기말	평균\n");  //위로 빼기
		printf("%s	%d	%d	%d\n", s[i].name, s[i].midterm, s[i].final, s[i].average);
	}

	for (i = 0; i < 3; i++) {
		if (s[i].average >= 80)
			s[i].grade = 'A';
		else if (s[i].average >= 50)
			s[i].grade = 'B';
		else
			s[i].grade = 'C';  //이거 F임..
	}

	printf("\n");
	for (i = 0; i < 3; i++) {
		printf("이름	학점\n");  //위로 빼야 함..
		printf("%s	%c\n", s[i].name, s[i].grade);
	}

	for (i = 0; i < 3; i++) {
		m += s[i].midterm;
		f += s[i].final;
	}
	m = m / 3;
	f = f / 3;

	printf("\n");
	printf("중간고사의 평균 = %d\n", m);
	printf("기말고사의 평균 = %d\n", f);
}