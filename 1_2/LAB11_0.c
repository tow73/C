#include <stdio.h>
int main(void)
{
	/*struct foo_t {
		int x;
		int y;
		char c;
		char c2;
	};*/
	struct foo_t {
		char c;
		int x;
		char c2;
		int y;
	};
	struct foo_t data;
	struct foo_t* ptr = &data, * ptr2;
	ptr2 = ptr;
	ptr2++;
	// ��)
	printf("sizeof data is = %d\n", sizeof(data)); //a)
	printf("data�� ù �ּҰ��� %d\n", &data); //b)
	printf("data.x ù �ּҰ��� %d\n", &data.x); //c)
	printf("ptr�� ����Ű�� �ּҰ��� %d\n", ptr); //d)
	printf("ptr2�� ����Ű�� �ּҰ��� %d\n", ptr2);//e)
	return;
}