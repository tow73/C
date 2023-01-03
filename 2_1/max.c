#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int right_max_sum(int* A, int left, int right)
{
	int i;
	int sum = 0;
	int max = A[left];

	for (i = left; i <= right; i++) {
		sum += A[i];

		if (max < sum)
			max = sum;
	}
	return max;
}
int left_max_sum(int* A, int left, int right)
{
	int i;
	int sum = 0;
	int max = A[right];

	for (i = right; i >=left; i--) {
		sum += A[i];

		if (max < sum)
			max = sum;
	}
	return max;
}
int max_subarray(int* A, int left, int right)
{
	int v1, v2, v3, mid; 

	if (left >= right)
		return A[right];
	else {
		mid = (left + right) / 2;
		v1 = max_subarray(A, left, mid);
		v2 = max_subarray(A, mid + 1, right);
		v3 = left_max_sum(A, left, mid - 1) + right_max_sum(A, mid, right);

		if (v1 > v2 && v1 > v3)
			return v1;
		else if (v2 > v1 && v2 > v3)
			return v2;
		else
			return v3;
	}
}
int main(void)
{
	int num, lastIndex, max;
	int* A;

	scanf("%d", &num);
	A = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
		scanf("%d", &A[i]);

	lastIndex = num - 1;
	max = max_subarray(A, 0, lastIndex);

	printf("%d\n", max);
}