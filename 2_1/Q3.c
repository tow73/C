#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ones(int len)
{
    int i;
    int add = 0;

    for (i = 0; i < len; i++)
        add = add * 10 + 1;

    return add;
}
int main(void)
{
    int num;
    int one = 0;
    int count = 1;

    scanf("%d", &num);

    while (1) {
        one = ones(count);

        if (one % num == 0)
            break;

        count++;
    }
    printf("%d", count);
}