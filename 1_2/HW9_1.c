#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
	char string[50]; // �ԷµǴ� ���ڿ��� ����
	char alphaString1[50] = ""; // �Է¹��ڿ����� ���ĺ��� ����
	char alphaString2[50] = ""; // ��ҹ��ڸ� �ٲ�
	char digitString[50] = "";
	char convertedString[50]; // ���ڵ�� ���ڵ�� ��迭�� ���ڿ�
	int i;
	char* p = string;

	printf("���ڿ��� �Է��ϼ���:");
	fgets(string, 50, stdin);
	
	while (*p) {  //for�� ������ ��
		if (isalpha(*p))
			strncat(alphaString1, p, 1);
		else if (isdigit(*p))
			strncat(digitString, p, 1);
		p++;
	}

	printf("���ڵ��� %s\n", alphaString1);
	printf("���ڵ��� %s\n", digitString);
	
	for (i = 0; i < strlen(alphaString1); i++) {
		if (isupper(alphaString1[i]))
			alphaString2[i] = tolower(alphaString1[i]);
		else
			alphaString2[i] = toupper(alphaString1[i]);
	}

	printf("��ҹ��ڸ� �ٲ� ���ڵ��� %s\n", alphaString2);

	strcpy(convertedString, alphaString1);
	strcat(convertedString, digitString);
	printf("���ڵ�� ���ڵ�� ��迭�� ���ڿ��� %s\n", convertedString);
}