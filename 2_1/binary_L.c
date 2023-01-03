#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int list[20] = { 2,5,16,19,20,25,31,39,43,49,56,57,63,68,72,77,81,84,90,96 };
int search_binary2(int key, int low, int high)
{
    int middle;
    while (low <= high) {
        middle = (low + high) / 2;
        if (key == list[middle])
            return middle;
        else if (key > list[middle])
            low = middle + 1;
        else
            high = middle - 1;
    }
    return -1;
}
int main(void)
{
    int num, bi;

    printf("Enter a num(0~100): ");
    scanf("%d", &num);

    bi = search_binary2(num, 0, 19);
    if (bi == -1)
        printf("There is no number");
    else
        printf("There is a number '%d' in list[%d]", num, bi);
}