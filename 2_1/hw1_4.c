#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num[5];
	int key, i;
	int count = 0;

	printf("Enter 5���� ����: ");
	for (i = 0; i < 5; i++)
		scanf("%d", &num[i]);
	while (getchar() != '\n');
	printf("Enter a key: ");
	scanf("%d", &key);

	for (i = 0; num[i] != '\0'; i++) {
		if (num[i] == key) {
			count  = i + 1;
			break;
		}
	}
	if (i == 5)
		printf("����");
	else
		printf("%d��°�� �ִ�", count);
}