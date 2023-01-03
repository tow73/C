#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mergeString(char c[], char a[], char b[])
{
	int i, j, k, l;
	char empty;

	for (i = 0; a[i] != '\0'; i++)
		c[i] = a[i];
	for (j = 0; b[j] != '\0'; j++) {
		c[i] = b[j];
		i++;
	}
	c[i] = '\0';
	for (k = 0; k < i; k++)
	{
		for (l = k + 1; l < i; l++)
		{
			if (c[k] > c[l])
			{
				empty = c[k];
				c[k] = c[l];
				c[l] = empty;
			}
		}
	}
	return c;
	/*
	int i = 0;
	int j = 0;
	int index = 0;

	while(a[i] != '\0' &&b[i] != '\0') {
		if(a[i] < b[j]) {
			c[index] = a[i];
			index++;
			i++
		}
		else {
			c[index] = b[j];
			index++;
			j++
		}
	}
	while(a[i] != '\0')
		c[index++] = a[i++];
	while(b[j] != '\0')
		c[index++] = b[j++];
	
	c[index] = '\0'
	return c;
	*/
}
int main(void)
{
	char word1[10], word2[10];
	char mergedWord[20];

	scanf("%s", word1);
	scanf("%s", word2);
	mergeString(mergedWord, word1, word2);
	printf("%s\n", mergedWord);
}