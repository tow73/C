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
	printf("arr의 합은 %d\n", sumUp(arr, 5)); // A) 배열이름과 그 크기를 인수로 호출한다! 
										   // arr = &arr[0] 
} 