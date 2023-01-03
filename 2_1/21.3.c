#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int row, col, start, c, r, finish;
	int ladder[100][100];

	scanf("%d %d", &col, &row);
	scanf("%d", &start);
	/*for (i = 0; i < row; i++)  //ladder는 char, 한 번에 한 줄 입력받기
		scanf("%s", ladder[i]);*/ 
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row - 1; j++)
			scanf("%d", &ladder[i][j]);

	/*for (i = 0; i < row; i++) {
		if (start == 0) {
			if (ladder[i][start] == '1')
				start++;
		}
		else if (start == col - 1) {
			if (ladder[i][start - 1] == '1')
				start--;
		}
		else {
			if (ladder[i][start] == '1')
				start++;
			else if (ladder[i][start - 1] == '1')
				start--;
		}

		if (start != col - 1 && ladder[i][start] == '1')
			start++;
		else if (start != 0 && ladder[i][start - 1] == '1')
			start--;
	}
	printf("%d", start);*/

	c = 0;
	r = start;
	finish = start;
	while (c != col) {
		if (ladder[c][r - 1] == 1) {
			r = r - 1;
			c++;
			finish = finish - 1;
		}
		else if (ladder[c][r + 1] == 1) {
			r = r + 1;
			c++;
			finish = finish + 1;
		}
		else
			c++;
	}
	printf("%d", finish);
}