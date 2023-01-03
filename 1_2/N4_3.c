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


// 필요한 함수들의 정의를 추가해서 이를 제출

int main(void) // 변경하지 말라
{
	CClass cClass;

	cClass.num = 0; // 초기에는 학생수 0

	readClass(&cClass);
	calculateClassGrade(&cClass); // 학점 계산
	printClass(&cClass); // 학생 정보를 출력
}
