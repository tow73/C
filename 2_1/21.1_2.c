#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse(char src_s[], char s[])
{
    long long i, len;

    len = strlen(src_s);
    for (i = len - 1; i >= 0; i--)
        s[len - i - 1] = src_s[i];
    s[len] = '\0';
}
int main(void)
{
    char num1[500], num2[500];
    char n1[500], n2[500];
    int len, i;
    int carry = 0;
    int count = 0;

    scanf("%s %s", num1, num2);

    reverse(num1, n1);
    reverse(num2, n2);
    if (strlen(num1) > strlen(num2))
        len = strlen(num1);
    else
        len = strlen(num2);


    /*for (i = 0; i < len; i++) {
        t1 = (n1[i] == 0(NULL)) ? 0 : n1[i] - '0';
        t2 = (n2[i] == 0(NULL)) ? 0 : n2[i] - '0';
        t3 = t1 + t2 + carry;
        if (t3 > 9) {
            carry = 1;
            count++;
        }
        else
            carry = 0;
    }*/
    for (i = 0; i < len; i++) {
        if (n1[i] >= 48 && n2[i] >= 48) {
            if ((n1[i] - '0') + (n2[i] - '0') + carry >= 10) {
                carry = 1;
                count++;
            }
            else
                carry = 0;
        }
        else if (n1[i] >= 48 && n2[i] < 48) {
            if ((n1[i] - '0') + carry >= 10) {
                carry = 1;
                count++;
            }
            else
                carry = 0;
        }
        else if (n1[i] < 48 && n2[i] >= 48) {
            if ((n2[i] - '0') + carry >= 10) {
                carry = 1;
                count++;
            }
            else
                carry = 0;
        }
        else
            carry = 0;
    }
    printf("%d", count);
}