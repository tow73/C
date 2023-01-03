#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
void print_list(ListNode* head) // Ʋ��(�����ؾ�)
{ 
	ListNode* p;
	if (head == NULL)
		return;
	p = head->link;
	while (p != head) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("%d->", p->data);  // ������ ��� ���
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
	return head;    //����� ��� �����͸� ��ȯ�Ѵ�. 
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
		head = node;  //ù ����, ������ ������ ����
	}
	return head;    // ����� ��� �����͸� ��ȯ�Ѵ�. 
}
ListNode* delete_first(ListNode* head)
{
	ListNode *temp;
	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) {  //node �� ��
		temp = head;
		head = NULL;
		//head->link = head;  //��¥�� NULL->��� ��
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
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) {  //node �� ��
		temp = head;
		head = NULL;
		//head->link = head;  //��¥�� NULL->��� ��
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
		printf("����Ʈ�� ��� �־� ã�� ������ ����\n");
		return NULL;
	}
	p = head;
	do {
		if (p->data == data)
			return p;
		p = p->link;
	} while (p != head);
	printf("ã�� ������ ����\n");
	return NULL;
}
int get_size(ListNode* head)
{
	ListNode *p = head->link;
	int count = 0;
	if (head == NULL) {
		printf("����Ʈ�� ��� ����\n");
		return 0;
	}
	do {
		p = p->link;
		count++;
	} while (p != head->link);
	return count;
}
// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
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
		printf("data ����\n");
	else
		printf("data ����\n");
	printf("list size: %d\n", get_size(head));

	free(head);
	free(p);
	return 0;
}