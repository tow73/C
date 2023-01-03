#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3
#define MAX_STR_SIZE 100
typedef struct {
	int num;
	char num_call[MAX_STR_SIZE];
}element;  //스택을 위한 타입 정리
element data[MAX_STACK_SIZE];
int top = -1;
void init()  //스택 초기화 함수
{
	top = -1;
}
int is_empty()  //공백 상태 검출 함수
{
	return (top == -1);
}
int is_full()  //포화 상태 검출 함수
{
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item)  //삽입함수
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		data[++top] = item;
}
element pop()  //삭제함수
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return data[top--];
}
element peek()  //피크함수
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return data[top];
}
void stack_print()  //스택 모습 출력
{
	int i;
	if (is_empty())
		printf("<empty>\n");
	else {
		printf("[%d, %s] <- top\n", peek().num,peek().num_call);

		for (i = top - 1; i >= 0; i--)
			printf("[%d, %s]\n", data[i].num,data[i].num_call);
	}
	printf("--\n");
}
void main()
{
	element e = {""};
	
	init(e);
	stack_print();
	element e1 = { 10,"ten" };
	push(e1);
	stack_print();
	element e2 = { 20,"twenty" };
	push(e2);
	stack_print();
	element e3 = { 30,"thirty" };
	push(e3);
	stack_print();
	element e4 = { 40,"forty" };
	push(e4);
	stack_print();
	pop();
	stack_print();
	element e5 = { 50,"fifty" };
	push(e5);
	stack_print();
	pop();
	stack_print();
	pop();
	stack_print();
	pop();
	stack_print();
}