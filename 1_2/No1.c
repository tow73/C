#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char sentence[81];

    printf("Enter the sentence: ");
    gets(sentence);

    if (solution(sentence) == 1)
        printf("It is palindrome.\n");
    else
        printf("It is not palindrome.\n");
}
int solution(char s[])
{
    int i, len = 0;
    char s2[81];

    for (i = 0; s[i] != '\0'; i++) {
        if (isupper(s[i])) {
            s2[len] = tolower(s[i]);
            len++;
        }
        else if (islower(s[i])) {
            s2[len] = s[i];
            len++;
        }
    }
    s2[len] = '\0';

    for (i = 0; i < len / 2; i++)
        if (s2[i] != s2[len - 1 - i])
            return 0;
    return 1;
}