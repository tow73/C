#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
void print_list(ListNode* head) // 틀림(수정해야)
{ 
	ListNode* p;
	if (head == NULL)
		return;
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->", p->data);  // 마지막 노드 출력
	printf("\n"); 
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head; //head(link) = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;    //변경된 헤드 포인터를 반환한다. 
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;  //head(link) = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;  //첫 삽입, 마지막 삽입의 차이
	}
	return head;    // 변경된 헤드 포인터를 반환한다. 
}
ListNode* delete_first(ListNode* head)
{
	ListNode *temp;
	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else if (head == head->link) {  //node 한 개
		temp = head;
		head = NULL;
		//head->link = head;  //어짜피 NULL->없어도 됨
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp;
	ListNode *p = head->link;
	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else if (head == head->link) {  //node 한 개
		temp = head;
		head = NULL;
		//head->link = head;  //어짜피 NULL->없어도 됨
		free(temp);
	}
	else {
		temp = head;
		while (p->link != head)
			p = p->link;
		p->link = head->link;
		head = p;
		free(temp);
	}
	return head;
}
ListNode* search(ListNode* head, element data)
{
	ListNode *p;
	if (head == NULL) {
		printf("리스트가 비어 있어 찾는 데이터 없음\n");
		return NULL;
	}
	p = head;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != head);
	printf("찾는 데이터 없음\n");
	return NULL;
}
int get_size(ListNode* head)
{
	ListNode *p = head->link;
	int count = 0;
	if (head == NULL) {
		printf("리스트가 비어 있음\n");
		return 0;
	}
	do {
		p = p->link;
		count++;
	} while (p != head->link);
	return count;
}
// 원형 연결 리스트 테스트 프로그램
int main(void) 
{
	ListNode *head = NULL;
	// list = 10->20->30->40
	head = insert_last(head, 20); print_list(head);
	head = insert_last(head, 30); print_list(head);
	head = insert_last(head, 40); print_list(head);
	head = insert_first(head, 10); print_list(head);
	head = delete_first(head); print_list(head);

	ListNode *p = search(head, 30);
	printf("search 30: ");
	if (p == NULL)
		printf("data 없음\n");
	else
		printf("data 있음\n");
	printf("list size: %d\n", get_size(head));

	free(head);
	free(p);
	return 0;
}