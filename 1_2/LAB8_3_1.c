#include <stdio.h>
void stringCopy(char* s1, const char* s2)// *s2�� �ٲ��������Ƿ� const�� ���ϼ�
{
	while (*s2)
	{
		*s1 = *s2;  //�� ���� ���ص� ��
		s1++;
		s2++;
	}
	*s1 = '\0';
}
int stringLength(char* co)
{
	int num = 0;
	while (*co) {
		co++;
		num++;
	}
	return num;
}
int main(void)
{
	char copied[500];
	char data1[] = "abcde";
	char data2[] = "ABCDEFGH";
	stringCopy(copied, data1);
	printf("ù��° ������ copied�� ���̿� ���� %d�� %s�̴�.\n", stringLength(copied), copied);
	stringCopy(copied, data2);
	printf("�ι�° ������ copied�� ���̿� ���� %d�� %s�̴�.\n", stringLength(copied), copied);
}