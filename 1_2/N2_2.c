#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char sentence[50]; // 총 49이하의 문자들로 문장 구성

	char delimiters[] = " ,\n\0"; // 네 개의 분리 문자들(공백,콤마,줄바꿈,널문자) 지정한다 
	char* token;
	int sum = 0;

	gets(sentence);

	// 이하 코드 작성






	printf("%d\n", sum);
}
