#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STRING 81
#define BOOL int
#define TRUE 1
#define FALSE 0
// Palindrome �˻�
BOOL isPalindrome(char str[]);
int main(void)
{
	char str[MAX_STRING];
	printf("* Palindrome üũ\n\n");
	printf("���ڿ� �Է�(���ڼ� %d ����): ", MAX_STRING);
	scanf("%s", str);
	if (isPalindrome(str)) // Palindrome �˻�
		printf("\"%s\" is a Palindrome\n\n", str); // ���� ����Ϸ��� \���� ���
	else
		printf("\"%s\" isn't a Palindrome\n\n", str);
	return 0;
}
BOOL isPalindrome(char s[])
{
	int i, j, k;

	i = 0;
	while (s[i] != '\0') {
		for (k = 0; s[k] != '\0'; k++);
		for (j = k - 1; j >= 0; j--) {
			if (s[i] != s[j])
				return FALSE;
			i++;
		}
	}
	return TRUE;
	/* �̷��� ����..
	int i, len;
	for(len = 0;s[len] != '\0'; len++);
	for(i = 0; i < len / 2; i++)
		if(s[i] != s[len - i -1])
			return FALSE;
	return TRUE;
	*/
}