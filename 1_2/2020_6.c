#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int is_word_in_word(char w1[], int start, char w2[]);
int main(void)
{
	char s1[20], s2[20];
	int i, j;

	scanf("%s", s1);
	scanf("%s", s2);

	for (i = 0; s1[i] != '\0'; i++)
		printf("%d", is_word_in_word(s1, i, s2));
}
int is_word_in_word(char w1[], int start, char w2[])
{
	int i = 0;
	int j, k;
	int count = 0;
	for (k = 0; w2[k] != '\0'; k++);
	while (w2[i] != '\0') {
		for (j = start; count != k; j++) {
			if (w2[i] != w1[j])
				return 0;
			i++;
			count++;
		}
		return 1;
	}
	/*  이렇게 만들기
	int i;
	for(i = 0; w2[i] != '\0'; i++) {
		if(w1[start] != w2[i])
			return 0;
		else
			start++;
	}
	return 1;
	*/
}