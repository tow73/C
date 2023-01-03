#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
    int n1, n2, r1, r2;
    int carry = 0;
    int count = 0;

    scanf("%d %d", &n1, &n2);

    while (n1 != 0 || n2 != 0) {
        r1 = n1 % 10;
        r2 = n2 % 10;

        if (r1 + r2 + carry >= 10) {
            carry = 1;
            count++;
        }
        else
            carry = 0;

        n1 /= 10;
        n2 /= 10;
    }
    printf("%d", count);

    return 0;
}