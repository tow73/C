#define WIDTH 10
#define HEIGHT 10
#include <stdio.h>
int screen[WIDTH][HEIGHT] = {
0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,
-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1, 0, 0, 0,-1, 0, 0, 0,-1,
-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,
-1,-1,-1,-1, 0,-1, 0,-1, 0,-1,
-1,-1,-1,-1, 0,-1,-1,-1, 0,-1,
-1,-1,-1,-1, 0, 0, 0, 0, 0, 0
};
int flood_fill(int x, int y, int count)
{
	if (screen[x][y] == 0 && x + 1 <= WIDTH && y + 1 <= WIDTH && x - 1 > -2 && y - 1 > -2)
	{
		screen[x][y] = count++;
		count = flood_fill(x, y + 1, count);
		count = flood_fill(x + 1, y, count);
		count = flood_fill(x, y - 1, count);
		count = flood_fill(x - 1, y, count);
		return count;
	}
	return count;
}
void draw_maze()
{
	int i, j;

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%3d", screen[i][j]);
		printf("\n");
	}
}
int main(void)
{
	printf("미로:\n");
	draw_maze();
	printf("\n");
	flood_fill(0, 0, 1);
	printf("시작점을 (0 0)으로 한 미로방문(순서표기):\n");
	draw_maze();
}