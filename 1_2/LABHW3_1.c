#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int list[10] = { 10, 20, 30, 40, 50, 40, 30, 20, 10, 0 };
	int value;
	int keyIndex;
	printf("���� %d\n", sumList(list, 10));
	printf("���� ū ���� %d\n", maxList(list, 10));
	printf("Ž���� ����? ");
	scanf("%d", &value);

	keyIndex = indexSearch(list, 10, value);
	if (keyIndex == -1)
		printf("�� %d�� ���� ���� �����ϴ�.", value);
	else
		printf("�� %d�� ���� ù��° ���� %d��°�� �ֽ��ϴ�.", value, keyIndex);
}
int sumList(int arr[], int size)
{
	int i, total = 0;
	for (i = 0; i < size; i++)
		total += arr[i];
	return total;
}
int maxList(int arr[], int size)
{
	int i, max = -999;
	for (i = 0; i < size; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}
int indexSearch(int arr[], int size, int key)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (key == arr[i])
			return i + 1;
	}		
	if (i = size - 1)  //��� �� �� �׳� return -1�� ���ָ� �� ��
		return -1;
}