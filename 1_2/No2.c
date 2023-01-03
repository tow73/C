#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int num;

    printf("Enter a num: ");
    scanf("%d", &num);
    printf("Change: %d", solution(num));
}
int solution(int n) {
    /*int answer = 0;  //변수 하나 더 생성

    while (n > 0) {
        answer *= 10;  //변수 = n % 10;
        answer += (n % 10);  //answer = answer * 10 + 변수;
        n = n / 10;
    }*/
    int rest, answer = 0;

    while (n > 0) {
        rest = n % 10;
        answer = answer * 10 + rest;
        n = n / 10;
    }

    return answer;
}