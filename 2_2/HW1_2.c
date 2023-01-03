#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STRING 100
typedef char element;  //스택을 위한 타입 정리
typedef struct {
	element data[MAX_STRING];
	int top;
} StackType;
void init(StackType* s)  //스택 초기화 함수
{
	s->top = -1;
}
int is_empty(StackType* s)  //공백 상태 검출 함수
{
	return (s->top == -1);
}
int is_full(StackType* s)  //포화 상태 검출 함수
{
	return (s->top == (MAX_STRING - 1));
}
void push(StackType* s, element item)  //삽입함수
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
element pop(StackType* s)  //삭제함수
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
element peek(StackType* s)  //피크함수
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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
		printf("palindrome 입니다.\n");
	else
		printf("palindrome이 아닙니다.\n");
}