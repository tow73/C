#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char id[15];
	char start[3];
	int s, year;
	char *first, *second;
	char se[2];

	printf("�ֹε�Ϲ�ȣ �Է�('-' ����): ");
	gets(id);

	strncpy(start, id, 2);
	start[2] = '\0';
	s = atoi(start);

	if (s < 10)
		printf("����� 190%d�⵵ ���̱���\n", s);
	else
		printf("����� 19%d�⵵ ���̱���\n", s);


	year = 1900 + atoi(start);
	first = strtok(id, "-");
	second = strtok(NULL, " ");
	strncpy(se, second, 1);
	se[1] = '\0';
	
	if (se[0] == '1') {   //�׳� id[7] == '1' �̷� ������ �ᵵ ��
		printf("���ں��̽ñ���\n");
		printf("��� ���� 77�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.", year + 77);
	}
	else {
		printf("���ں��̽ñ���\n");
		printf("��� ���� 84�� ���ϸ� %d���� ��ٰ� ���˴ϴ�.", year + 84);
	}

	return 0;
}