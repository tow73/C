#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;
//스택을 위한 타입 정의 
typedef TreeNode* element;
typedef struct StackNode {
	element data;
	struct StackNode *link;
} StackNode;
typedef struct {
	StackNode *top;
} LinkedStackType;
//여기에 연결된 스택 프로그램 함수를 추가
void init(LinkedStackType* s)
{
	s->top == NULL;
}
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}
element pop(LinkedStackType* s)
{
	StackNode* temp = s->top;
	int data = temp->data;
	s->top = s->top->link;
	free(temp);
	return data;
}
void inorder_iter(TreeNode* root)
{
	StackNode s;
	init(&s);

	while (1) {
		for (; root; root = root->left)
			push(&s, root);
		root = pop(&s);
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;
int main(void)
{
	printf("중위 순회 = ");
	inorder_iter(root);
	printf("\n");

	return 0;
}


