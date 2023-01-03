#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3
#define MAX_STR_SIZE 100
typedef struct {
	int num;
	char num_call[MAX_STR_SIZE];
}element;  //������ ���� Ÿ�� ����
element data[MAX_STACK_SIZE];
int top = -1;
void init()  //���� �ʱ�ȭ �Լ�
{
	top = -1;
}
int is_empty()  //���� ���� ���� �Լ�
{
	return (top == -1);
}
int is_full()  //��ȭ ���� ���� �Լ�
{
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item)  //�����Լ�
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		data[++top] = item;
}
element pop()  //�����Լ�
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return data[top--];
}
element peek()  //��ũ�Լ�
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return data[top];
}
void stack_print()  //���� ��� ���
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