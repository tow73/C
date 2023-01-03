#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char fullName[50];
	char lastName[50] = "Pak";
	char firstName[50] = "Suehee";
	char id[15] = "630826-2020222"; // 14 개의 문자 + '\0'
	char idFront[7];

	strcpy(fullName, lastName);  //strcat(lastName, ", ")
	strcat(fullName, ", ");  //strncat(lastName, firstName, 6) or strcat(lastName, firstName) but lastName이 바뀜
	strcat(fullName, firstName);  //strcpy(fullName, lastName)
	printf("당신의 fullname 은 %s\n", fullName);
	
	strncpy(idFront, id, 6);
	idFront[6] = '\0';
	printf("주민등록번호 앞자리는 %s\n", idFront);
}