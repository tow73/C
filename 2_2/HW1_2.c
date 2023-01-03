#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STRING 100
typedef char element;  //������ ���� Ÿ�� ����
typedef struct {
	element data[MAX_STRING];
	int top;
} StackType;
void init(StackType* s)  //���� �ʱ�ȭ �Լ�
{
	s->top = -1;
}
int is_empty(StackType* s)  //���� ���� ���� �Լ�
{
	return (s->top == -1);
}
int is_full(StackType* s)  //��ȭ ���� ���� �Լ�
{
	return (s->top == (MAX_STRING - 1));
}
void push(StackType* s, element item)  //�����Լ�
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
element pop(StackType* s)  //�����Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
element peek(StackType* s)  //��ũ�Լ�
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
int palindrome(char str[])
{
	StackType s;
	int i;

	init(&s);
	for (i = 0; str[i] != '\0'; i++)
		push(&s, str[i]);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != pop(&s))
			return 0;
	return 1;
}
int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf("%s", word);

	if (palindrome(word))
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome�� �ƴմϴ�.\n");
}