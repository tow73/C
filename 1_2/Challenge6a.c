#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char first[25] = { 0 };
	char second[25] = { 0 };
	int i;  //same �ϳ� �� ���� if(same)�̸� ����, �ƴϸ� �ٸ���

	printf("Enter the first word: ");
	scanf("%s", &first);
	printf("Enter the second word: ");
	scanf("%s", &second);

	for (i = 0; i < 25; i++) {  //first[i] != '\0' || second[i] != '\0' ���� �̰ɷ� ���ֱ�
		if (first[i] != second[i]) {
			printf("�� �ܾ�� �ٸ���.");
			return;
		}
	}
	printf("�� �ܾ�� ����.");
	return;
}