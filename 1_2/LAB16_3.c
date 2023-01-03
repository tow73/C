#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char text[][10] = { "ABC", "abcd", "Hello" };
	int i, j;

	printf("가) text의 메모리 크기는 %d이다.\n", sizeof(text));
	for (i = 0; i < 3; i++)
	{
		printf("%d번째 스트링: %s, ", i + 1, text[i]);  //text[i]는 문자열 배열로 볼 수 있음
		printf("아스키 코드값: ");
		for (j = 0; text[i][j] != '\0'; j++)
			printf("%d ", text[i][j]);
		printf("\n");
	}
}