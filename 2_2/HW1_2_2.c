#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct {
	int num;
	char num_call[100];
}StackData;
typedef struct StackNode {
	StackData data;
	struct StackNode* link;
}StackNode;
typedef struct {
	StackNode* top;
} LinkedStackType;
void init(LinkedStackType* s)
{
	s->top = NULL;
}
int is_empty(LinkedStackType* s)
{
	return (s->top == NULL);
}
int is_full(LinkedStackType* s)
{
	return 0;
}
void push(LinkedStackType* s, StackData item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->data = item;
		temp->link = s->top;
		s->top = temp;
	}
}
StackData pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		StackData data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
StackData peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}
void print_stack(LinkedStackType* s)
{
	if (is_empty(s))
		printf("(empty)\n");
	else {
		printf("[%d, %s] <- top\n", peek(s).num, peek(s).num_call);

		for (StackNode* p = s->top->link; p != NULL; p = p->link)  // *p = s->top; ?
			printf("[%d, %s]\n", p->data.num, p->data.num_call);
	}
	printf("--\n");
}
void main()
{
	LinkedStackType s;
	StackData sd;

	init(&s); print_stack(&s);
	sd.num = 10; strcpy(sd.num_call, "ten");
	push(&s, sd); print_stack(&s);
	sd.num = 20; strcpy(sd.num_call, "twenty");
	push(&s, sd); print_stack(&s);
	sd.num = 30; strcpy(sd.num_call, "thirty");
	push(&s, sd); print_stack(&s);
	sd.num = 40; strcpy(sd.num_call, "forty");
	push(&s, sd); print_stack(&s);
	pop(&s); print_stack(&s);
	sd.num = 50; strcpy(sd.num_call, "fifty");
	push(&s, sd); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);

	return 0;
}