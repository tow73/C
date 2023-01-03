#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int calculateReverse(int n)
{
    int reverse = 0;

    while (n != 0) {
        reverse *= 10;
        reverse += (n % 10);
        n /= 10;
    }
   
    return reverse;
}
int main(void)
{
    int num, ori, re;
    int count = 0;
    
    scanf("%d", &num);

    ori = num;
    re = calculateReverse(ori);

    while (ori != re) {
        count++;
        ori = ori + re;
        re = calculateReverse(ori);

        if (count > 1000) {
            printf("NaN");
            return 0;
        }
    }
    printf("%d %d", count, ori);
    return 0;
}