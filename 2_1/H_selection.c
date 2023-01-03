#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
	int id;
	int korean, math, english;
} Student;
void selection(int n, Student* st)
{
	int i, j, max, temp;

	for (i = 0; i < n - 1; i++) {
		max = 0;
		for (j = 0; j < n - i ; j++) {
			if (st[max].korean < st[j].korean)
				max = j;
		}

		temp = st[max].id;
		st[max].id = st[n - i - 1].id;
		st[n - i - 1].id = temp;
		temp = st[max].korean;
		st[max].korean = st[n - i - 1].korean;
		st[n - i - 1].korean = temp;
		temp = st[max].math;
		st[max].math = st[n - i - 1].math;
		st[n - i - 1].math = temp;
		temp = st[max].english;
		st[max].english = st[n - i - 1].english;
		st[n - i - 1].english = temp;
	}
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
		printf("%d: %d, %d, %d\n", s[i].id, s[i].korean, s[i].math, s[i].english);

	selection(num, s);
	printf("\nselection sort\n");
	for (i = num - 1; i >= 0; i--)
		printf("%d: %d, %d, %d\n", s[i].id, s[i].korean, s[i].math, s[i].english);

	free(s);
}