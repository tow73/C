#include <stdio.h>
void print_array(int pa[][3], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			printf("%d ", *(pa[i] + j));
}
int max_array(int pa[][3], int size)
{
	int i, j, max;
	max = -999;  //INT_MIN으로 놓기(stdlib.h 써야 할 수도 있음)
	for (i = 0; i < size; i++)
		for (j = 0; j < 3; j++)
			if (*(pa[i] + j) > max)
				max = *(pa[i] + j);
			
	return max;
}
int main(void)
{
	int array[][3] = { {1, 22, 70}, {23, 80, 34}, {90, 20, 4}, {40, 99, 30} };
	int rowNb = sizeof(array) / sizeof(array[0]);
	print_array(array, rowNb);
	printf("\n가장 큰 값은 %d\n", max_array(array, rowNb));
}