#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s1, const char* s2) {
	int answer = 0;
	int i;
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return answer;
	answer = 1;
	return answer;
}
int main(void)
{
	char word1[81];
	char word2[81];

	//printf("Enter the first word: ");
	scanf("%s", word1);
	//printf("Enter the second word: ");
	scanf("%s", word2);

	printf("%d\n", solution(word1, word2));

	return 0;
}