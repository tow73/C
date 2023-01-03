#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
	int id;
	int korean, math, english;
} Student;
void bubblesort(int n, Student* st, int b)
{
	int i, temp;

	if (b == 1) {
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
				bubblesort(n, st, b);
	}
	else if (b == 2) {
		for (i = 0; i < n - 1; i++) {
			if (st[i].math > st[i + 1].math) {
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
			if (st[i].math > st[i + 1].math)
				bubblesort(n, st, b);
	}
	else if (b == 3) {
		for (i = 0; i < n - 1; i++) {
			if (st[i].english > st[i + 1].english) {
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
			if (st[i].english > st[i + 1].english)
				bubblesort(n, st, b);
	}
	else if (b == 4) {
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
				bubblesort(n, st, b);
	}
}
void display(int n, Student* st, int key)
{
	int i;
	if (key == 1) {
		for (i = n - 1; i >= 0; i--)
			printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", st[i].id, st[i].english, st[i].math, st[i].korean);
	}
	else if (key == -1) {
		for (i = 0; i < n; i++)
			printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", st[i].id, st[i].english, st[i].math, st[i].korean);
	}
}
int main(void)
{
	int num, i, button;

	printf("학생 수를 입력하세요 : ");
	scanf("%d", &num);
	Student* s = (int*)malloc(sizeof(int) * num);

	srand(time(NULL));

	for (i = 0; i < num; i++) {
		s[i].id = i + 1;
		s[i].korean = rand() % 101;
		s[i].math = rand() % 101;
		s[i].english = rand() % 101;
	}
	display(num, s, -1);

	do {
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기): ");
		scanf("%d", &button);

		if (button == 1) {
			bubblesort(num, s, button);
			display(num, s, 1);
		}
		else if (button == 2) {
			bubblesort(num, s, button);
			display(num, s, 1);
		}
		else if (button == 3) {
			bubblesort(num, s, button);
			display(num, s, 1);
		}
		else if (button == 4) {
			bubblesort(num, s, button);
			display(num, s, -1);
		}
		else if (button == 0)
			break;
	} while (button != 0);
}