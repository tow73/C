#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int midterm;
	int final;
} Score;
void printScore(Score s) //2)
{
	printf("�߰���� ������ %d\n", s.midterm);
	printf("�б⸻��� ������ %d\n", s.final);
}
Score biggerScore(Score s1, Score s2) //3)
{
	int s11, s22;  //���� ������ ���� �ٷ� �ϱ�  //Score ���� ���� �ִ� �͵� ���� 
	s11 = s1.midterm + s1.final;
	s22 = s2.midterm + s2.final;
	if (s11 > s22)
		return s1;
	return s2;
}
Score totalScore(Score s1, Score s2) //4)
{
	Score total;
	total.midterm = s1.midterm + s2.midterm;
	total.final = s2.final + s2.final;
	return total;
}
Score createScore(int m, int f) //5)
{
	Score s3;
	s3.midterm = m;
	s3.final = f;
	return s3;
}
int main(void) {
	Score s1, s2, s3;
	s1.midterm = 50; s1.final = 100;
	s2.midterm = 70; s2.final = 70;
	printf("1)-----------------------------\n");
	printScore(s1);
	printScore(s2);
	printf("2)-----------------------------\n");
	printf("�� �� ������ ���� ����:\n");
	printScore(biggerScore(s1, s2));
	printf("3)-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(s1, s2));
	printf("4)-----------------------------\n");
	s3 = createScore(99, 99);
	printScore(s3);
}