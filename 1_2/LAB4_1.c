#include <stdio.h>
float g_i = 10.0;
float sum(float x, float y)
{
	return x + y;
}
float sum_2(float a, float b)
{
	return g_i + sum(a, b);
}
int main(void)
{
	fprintf(stdout, "계산 결과는 %f 입니다\n", sum_2(10, 20));
	return 0;
}