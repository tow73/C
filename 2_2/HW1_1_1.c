#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3
typedef int element;  //������ ���� Ÿ�� ����
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
void init(StackType *s)  //���� �ʱ�ȭ �Լ�
{
	s->top = -1;
}
int is_empty(StackType *s)  //���� ���� ���� �Լ�
{
	return (s->top == -1);
}
int is_full(StackType *s)  //��ȭ ���� ���� �Լ�
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType *s, element item)  //�����Լ�
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
element pop(StackType *s)  //�����Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
element peek(StackType *s)  //��ũ�Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
void stack_print(StackType *s)  //���� ��� ���
{
	int i;
	if (is_empty(s))
		printf("<empty>\n");
	else {
		printf("%d <- top\n", peek(s));

		for (i = s->top - 1; i >= 0; i--)
			printf("%d\n", s->data[i]);
	}
	printf("--\n");
}
void main()
{
	StackType s;

	init(&s);
	stack_print(&s);
	push(&s, 10);
	stack_print(&s);
	push(&s, 20);
	stack_print(&s);
	push(&s, 30);
	stack_print(&s);
	push(&s, 40);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}