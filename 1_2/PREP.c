#define MAX_SET_SIZE 10
#define HAVE_ELEMENT 1
#define DO_NOT_HAVE_ELEMENT 0
#include <stdio.h>
// set �� element �� ������ 1 �� ������ 0 �� ��ȯ�Ѵ�
int hasElement(int set[], int size, int element)
{
	int i;
	for (i = 0; i < size; i++)
		if (set[i] == element)
			return HAVE_ELEMENT; // we found it!
	return DO_NOT_HAVE_ELEMENT;
}
//set a, b ����
void printSet(int set[], int size)
{
	int i;
	printf("< ");
	for (i = 0; i < size; i++)
	{
		printf("%d", set[i]);
		if (i != size - 1)
			printf(", ");
	}	
	printf(" >\n");
}
// set1 �� set2 �� ������ 1 �� �ٸ��� 0 �� ��ȯ
int isSetEqual(int set1[], int size1, int set2[], int size2)
{
	int i;
	if (size1 != size2)
		return 0;
	else
	{
		for (i = 0; i < size1; i++)
			if (hasElement(set2, size2, set1[i]) == 0)
				return 0;
		return 1;
	}
	/*else
		for (i = 0; i < size2; i++)
		{
			for (j = 0; j < size1; j++)
				if (set2[i] == set1[j])
					break;
			if (j == size1)
				return 0;
		}
	if (i == size2)  //�� ���� ��� ��
		return 1;*/
}
// ���Ұ� ���տ� �������� ������ �߰�, �̹� �����ϸ� redundant ��� ����ϰ� ���� ���� ũ�⸦ ��ȯ
int addOneElement(int set[], int size, int element)
{
	if (hasElement(set, size, element) == 0)
	{
		set[size] = element;
		size++;
	}
	else
		printf("It is redundant. Please retry.\n");
	return size;
	/*int i;
	for (i = 0; i < size; i++)
		if (hasElement(set, size, element) == 1)
		{
			printf("It is rebundant. Please retry.\n");
			return size;
		}			

	if (i == size)  //�̰� �´� ��
	{
		set[size] = element;
		size++;
		return size;
	}*/
}
int main(void)
{
	int setA[MAX_SET_SIZE] = { 1, 2, 3 };
	int setB[MAX_SET_SIZE] = { 3, 2, 1, 4 };
	int num;
	int sizeA = 3, sizeB = 4;
	printf("A:"); printSet(setA, sizeA);
	printf("B:"); printSet(setB, sizeB);
	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("���� A �� B �� ����\n");
	else
		printf("���� A �� B �� �ٸ���\n\n");
	printf("A �� 3 �� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 3); // 3 �� SetA �� �߰��Ѵ�
	printf("���� A:"); printSet(setA, sizeA);
	printf("A �� 4 �� �߰��ϸ�\n");
	sizeA = addOneElement(setA, sizeA, 4); // 4 �� SetA �� �߰��Ѵ�
	printf("���� A:"); printSet(setA, sizeA);
	if (isSetEqual(setA, sizeA, setB, sizeB))
		printf("���� A �� B �� ����\n");
	else
		printf("���� A �� B �� �ٸ���\n");
}