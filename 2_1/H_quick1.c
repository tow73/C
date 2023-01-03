#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct student {
	int id;
	int korean, math, english;
};
int partician(struct student* A, int p, int r)
{
	int i = p - 1;
	int j = p;
	struct student temp;

	for (; j < r; j++) {
		if (A[j].korean < A[r].korean) {
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	i++;
	temp = A[i];
	A[i] = A[r];
	A[r] = temp;

	return i;
}
void quickSort(struct student* A, int p, int r)
{
	int q;

	if (p < r) {
		q = partician(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}
int main(void)
{
    struct student* A;
    int num, i;

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

	for (i = 0; i < num; i++)
		printf("%d-> korean: %d, math: %d, english: %d\n", A[i].id, A[i].korean, A[i].math, A[i].english);

	quickSort(A, 0, num - 1);

	printf("\nquick sort by Korean\n");
	for (i = num - 1; i >= 0; i--)
		printf("%d-> korean: %d, math: %d, english: %d\n", A[i].id, A[i].korean, A[i].math, A[i].english);

	free(A);
}