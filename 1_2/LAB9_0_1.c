#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main(void)
{
	char ch;
	while (1)
	{
		scanf("%c", &ch); // 예 1)
		// ch = getchar(); // 예 2): 띄어쓰기 가능
		// ch = fgetc(stdin); // 예 3): 띄어쓰기 가능
		// ch = getch(); // 예 4): q를 누르면 종료(q 포함 x)
		// ch = getche(); // 예 5): q를 누르면 종료(q 포함)
		if (ch == 'q') break;
		putch(ch); // printf("%c", ch), putchar(ch), fputc(ch, stdout)나 모두 같은 결과
	}
}