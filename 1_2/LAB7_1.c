#include <stdio.h>
int main(void)
{
	int x[] = { 0, 0, 1, 2, 3 };
	char c[] = "BBCDE";
	double f = 2.3;
	int i, sum = 0;
	// 가) 추가
	int* px = x;
	char* pc = c;
	double* pd = &f;
	printf("가-1) %d %c %.1f\n", x[0], c[0], f);
	printf("가-2) %d %c %.1f\n", *px, *pc, *pd);
	// 나) 추가
	*px = *px - 1;
	*pc = *pc - 1;
	*pd = *pd + 1.2;
	printf("나) %d %c %.1lf\n", x[0], c[0], f);
	// 다) 추가
	for (i = 0; i < sizeof(x) / sizeof(int); i++) {
		sum += *px;  // 한 줄에 써주기
		px++;
		//(sum += *px++; 도 가능)
	}
	printf("다) sum = %d\n", sum); // sum의 값은 5이다. x[0]의 값은 위에서 이미 -1로 수정
	// 라)
	px = x;
	for (i = 0; i < sizeof(x) / sizeof(int); i++)
	{
		*px = 100;  // 한 줄에 써주기
		px++; // 라-B)
	}
	// 마)
	pc = c;
	for (i = 0; i < sizeof(c) / sizeof(char); i++)
	{
		*pc = 'X';  // 한 줄에 써주기
		pc++; // 마-B)
	}
}