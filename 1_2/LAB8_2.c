#include <stdio.h>
int sumUp(int pa[], int size) // B)
{ 
	int i, sum = 0; 
	for (i = 0; i < size; i++) 
		sum += pa[i]; 
	return sum; 
} 
int main(void) 
{ 
	int arr[5] = {10, 20, 30, 40, 50}; 
	printf("arr�� ���� %d\n", sumUp(arr, 5)); // A) �迭�̸��� �� ũ�⸦ �μ��� ȣ���Ѵ�! 
										   // arr = &arr[0] 
} 