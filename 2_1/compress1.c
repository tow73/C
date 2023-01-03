#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void compress(char* s)
{
	char s2[1000];
	int i = 0;
	int size = 1;
	int j = 0;
	int count = 0;
	char copy;

	while (s[i] != '\0') {
		size++;
		i++;
	}
	for (i = 1; i < size; i++) {
		if (s[i - 1] == s[i]) {
			count++;
			copy = s[i];
		}
		else {
			if (count == 0) {
				s2[j] = s[i - 1];
				j++;
			}
			else {
				s2[j] = count + 49;
				s2[++j] = copy;
				j++;
				count = 0;
			}
		}
	}
	s2[j] = '\0';
	i = 0;
	size = 0;
	while (s2[i] != '\0') {
		size++;
		i++;
	}
	printf("%s\n%d\n", s2, size);
}
int main(void)
{
	char s[1000];

	scanf("%s", s);
	
	compress(s);
}