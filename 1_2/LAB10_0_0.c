#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	struct student {
		char name[20];
		int mid;
		int final;
	};
	struct student aStudent;
	
	printf("Enter student name: ");
	scanf("%s", aStudent.name);
	printf("Enter midterm and final score: ");
	scanf("%d %d", &aStudent.mid, &aStudent.final);

	printf("�̸�	�߰�	�б⸻\n");
	printf("%s	%d	%d\n", aStudent.name, aStudent.mid, aStudent.final);
}