#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char first[25] = { 0 };
	char second[25] = { 0 };
	int i;  //same 하나 더 만들어서 if(same)이면 같다, 아니면 다르다

	printf("Enter the first word: ");
	scanf("%s", &first);
	printf("Enter the second word: ");
	scanf("%s", &second);

	for (i = 0; i < 25; i++) {  //first[i] != '\0' || second[i] != '\0' 범위 이걸로 써주기
		if (first[i] != second[i]) {
			printf("두 단어는 다르다.");
			return;
		}
	}
	printf("두 단어는 같다.");
	return;
}