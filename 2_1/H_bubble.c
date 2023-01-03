#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
	int id;
	int korean, math, english;
} Student;
void bubbleSortDescendingByKorean(int n, Student* st)
{
	int i, temp;

	for (i = 0; i < n - 1; i++) {
		if (st[i].korean > st[i + 1].korean) {
			temp = st[i].id;
			st[i].id = st[i + 1].id;
			st[i + 1].id = temp;
			temp = st[i].korean;
			st[i].korean = st[i + 1].korean;
			st[i + 1].korean = temp;
			temp = st[i].math;
			st[i].math = st[i + 1].math;
			st[i + 1].math = temp;
			temp = st[i].english;
			st[i].english = st[i + 1].english;
			st[i + 1].english = temp;
		}
	}

	for (i = 0; i < n - 1; i++)
		if (st[i].korean > st[i + 1].korean)
			bubbleSortDescendingByKorean(n, st);
}
void bubbleSortAscendingById(int n, Student* st)
{
	int i, temp;

	for (i = 0; i < n - 1; i++) {
		if (st[i].id > st[i + 1].id) {
			temp = st[i].id;
			st[i].id = st[i + 1].id;
			st[i + 1].id = temp;
			temp = st[i].korean;
			st[i].korean = st[i + 1].korean;
			st[i + 1].korean = temp;
			temp = st[i].math;
			st[i].math = st[i + 1].math;
			st[i + 1].math = temp;
			temp = st[i].english;
			st[i].english = st[i + 1].english;
			st[i + 1].english = temp;
		}
	}

	for (i = 0; i < n - 1; i++)
		if (st[i].id > st[i + 1].id)
			bubbleSortAscendingById(n, st);
}
int main(void)
{
	int num, i;

	scanf("%d", &num);
	Student* s = (int*)malloc(sizeof(int) * num);

	srand(time(NULL));

	for (i = 0; i < num; i++) {
		s[i].id = i + 1;
		s[i].korean = rand() % 101;
		s[i].math = rand() % 101;
		s[i].english = rand() % 101;
	}
	printf("\n");

	for (i = 0; i < num; i++)
		printf("%d-> korean: %d, math: %d, english: %d\n", s[i].id, s[i].korean, s[i].math, s[i].english);

	bubbleSortDescendingByKorean(num, s);
	printf("\nbubble sort by Korean\n");
	for (i = num - 1; i >= 0; i--)
		printf("%d-> korean: %d, math: %d, english: %d\n", s[i].id, s[i].korean, s[i].math, s[i].english);

	bubbleSortAscendingById(num, s);
	printf("\nbubble sort by ID\n");
	for (i = 0; i < num; i++)
		printf("%d-> korean: %d, math: %d, english: %d\n", s[i].id, s[i].korean, s[i].math, s[i].english);

	free(s);
}