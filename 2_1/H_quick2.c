#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student {
    int id;
    int korean, math, english;
};
int partician(struct student* A, int p, int r, int b)
{
	int i = p - 1;
	int j = p;
	struct student temp;

	if (b == 1) {
		for (; j < r; j++) {
			if (A[j].korean < A[r].korean) {
				i++;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	else if (b == 2) {
		for (; j < r; j++) {
			if (A[j].math < A[r].math) {
				i++;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	else if (b == 3) {
		for (; j < r; j++) {
			if (A[j].english < A[r].english) {
				i++;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	else {
		for (; j < r; j++) {
			if (A[j].id < A[r].id) {
				i++;
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	i++;
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;

	return i;
}
void quickSort(struct student* A, int p, int r, int b)
{
	int q;

	if (p < r) {
		q = partician(A, p, r, b);
		quickSort(A, p, q - 1, b);
		quickSort(A, q + 1, r, b);
	}
}
void display(int n, struct student* A, int key)
{
	int i;
	if (key == 1) {
		for (i = n - 1; i >= 0; i--)
			printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}
	else if (key == -1) {
		for (i = 0; i < n; i++)
			printf("학번 : %d\t영어 : %d\t수학 : %d\t국어 : %d\n", A[i].id, A[i].english, A[i].math, A[i].korean);
	}
}
int main(void)
{
    struct student* A;
    int num, i, button;

	printf("학생 수를 입력하세요 : ");
    scanf("%d", &num);

    A = (struct student*)malloc(sizeof(struct student) * num);
    srand(time(NULL));

    for (i = 0; i < num; i++) {
        A[i].id = i + 1;
        A[i].korean = rand() % 101;
        A[i].math = rand() % 101;
        A[i].english = rand() % 101;
    }
	display(num, A, -1);

	do {
		printf("정렬 기준 선택(1:국어, 2:수학, 3:영어, 4:id(오름차순), 0:끝내기): ");
		scanf("%d", &button);

		if (button == 1) {
			quickSort(A, 0, num - 1, button);
			display(num, A, 1);
		}
		else if (button == 2) {
			quickSort(A, 0, num - 1, button);
			display(num, A, 1);
		}
		else if (button == 3) {
			quickSort(A, 0, num - 1, button);
			display(num, A, 1);
		}
		else if (button == 4) {
			quickSort(A, 0, num - 1, button);
			display(num, A, -1);
		}
		else if (button == 0)
			break;
	} while (button != 0);
}