#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char text[][10] = { "ABC", "abcd", "Hello" };
	int i, j;

	printf("��) text�� �޸� ũ��� %d�̴�.\n", sizeof(text));
	for (i = 0; i < 3; i++)
	{
		printf("%d��° ��Ʈ��: %s, ", i + 1, text[i]);  //text[i]�� ���ڿ� �迭�� �� �� ����
		printf("�ƽ�Ű �ڵ尪: ");
		for (j = 0; text[i][j] != '\0'; j++)
			printf("%d ", text[i][j]);
		printf("\n");
	}
}