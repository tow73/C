#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char fullName[50];
	char lastName[50] = "Pak";
	char firstName[50] = "Suehee";
	char id[15] = "630826-2020222"; // 14 ���� ���� + '\0'
	char idFront[7];

	strcpy(fullName, lastName);  //strcat(lastName, ", ")
	strcat(fullName, ", ");  //strncat(lastName, firstName, 6) or strcat(lastName, firstName) but lastName�� �ٲ�
	strcat(fullName, firstName);  //strcpy(fullName, lastName)
	printf("����� fullname �� %s\n", fullName);
	
	strncpy(idFront, id, 6);
	idFront[6] = '\0';
	printf("�ֹε�Ϲ�ȣ ���ڸ��� %s\n", idFront);
}