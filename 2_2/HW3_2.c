#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
	element data;
	struct ListNode *link;
} ListNode;
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
ListNode* insert_next(ListNode *head, ListNode *pre, element value) //pre뒤에 삽입 
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}
ListNode* insert_first(ListNode *head, int value)  //맨 앞에 삽입
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;  //없어도 됨, 절차
	p->link = head;  //포인터 값 복사
	head = p;  //포인터 값 변경
	return head;
}
ListNode* insert_last(ListNode *head, int value)  //맨 마지막에 삽입
{
	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	if (head == NULL)
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;
		temp->link = p;
	}
	return head;
}
ListNode* delete_next(ListNode *head, ListNode *pre)  //pre 다음 삭제
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
ListNode* delete_first(ListNode *head)  //맨 앞 삭제
{
	ListNode *removed;
	if (head == NULL)
		error("삭제할 항복이 없음");
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete_last(ListNode *head)  //맨 마지막 삭제
{
	ListNode* temp = head;
	ListNode *prevTemp = NULL;
	ListNode *removed = NULL;
	if (head == NULL)
		error("삭제할 항목이 없음");
	else if (head->link == NULL) {
		removed = head;
		head = NULL;
	}
	else {
		while (temp->link != 0) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
	}
	free(removed);
	return head;
}
void print_list(ListNode *head)
{
	ListNode *temp;
	for (temp = head; temp != NULL; temp = temp->link)
		printf("%d->", temp->data);
	printf("NULL\n");
}
ListNode* search(ListNode *head, int x)
{
	ListNode *p = head;
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
	return NULL;
}
ListNode* concat(ListNode *head1, ListNode *head2)
{
	ListNode *temp;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		temp = head1;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = head2;
		return head1;
	}
}
/*ListNode* reverse(ListNode* head)
{
	ListNode *p = head;
	ListNode *c = NULL;
	ListNode *n = NULL;

	while (p != NULL)
	{
		n = c;
		c = p;
		p = p->link;
		c->link = n;
	}
	return c;
}*/
int is_in_list(ListNode* head, element item)
{
	ListNode* temp = head;
	while (temp != 0) {  //temp!=NULL
		if (temp->data == item)
			return 1;
		temp = temp->link;
	}
	return 0;
}
int get_length(ListNode* head)
{
	ListNode *temp = head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->link;
	}
	return count;
}
int get_total(ListNode* head)
{
	ListNode* temp = head;
	int total = 0;
	while (temp != NULL) {
		total += temp->data;
		temp = temp->link;
	}
	return total;
}
element get_entry(ListNode* head, int pos)
{
	ListNode* temp = head;
	if (temp == NULL)
		error("%d 노드가 비어있음", pos);
	for (int i = 0; i < pos; i++) {
		temp = temp->link;
		if(temp == NULL)
			printf("%d 노드가 비어있음", pos);
	}
	return temp->data;
}
ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	if (head->data == key)
		head = delete_first(head);
	else {
		while (temp != NULL) {
			if (temp->data == key) {
				prevTemp->link = temp->link;
				temp->link = NULL;
				free(temp);
				return head;  //return delete_pos(head, i);
			}
			prevTemp = temp;  //i++;
			temp = temp->link;
		}
		printf("%d를 가진 노드가 없어 삭제 불가능\n", key);  //return문 위로 보내기
	}
	return head;
}
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	if (pos == 0)
		head = insert_first(head, value);  //바로 return하기
	else {
		for (int i = 0; i < pos; i++) {
			prevTemp = temp;
			temp = temp->link;
		}
		p->link = temp;
		prevTemp->link = p;
		/*for(int i=0; i<pos-1; i++)
			p=p->link;
		return insert_next(head,p,value);*/
	}
	return head;
}
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp = head;
	ListNode* prevTemp = head;
	if (pos == 0)
		head = delete_first(head);  //바로 return해도 됨
	else {
		for (int i = 0; i < pos; i++) {
			prevTemp = temp;
			temp = temp->link;
		}
		prevTemp->link = temp->link;
		free(temp);
		/*for(int i=0; i<pos-1; i++)
			p=p->link;
		return delete_next(head, temp);*/
	}
	return head;
}
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3; 
	for (int i = 1; i < 4; i++)
		list1 = insert_first(list1, i * 10);
	printf("list1 = "); print_list(list1);
	list1 = delete_first(list1);
	printf("list1 = "); print_list(list1);

	for (int i = 1; i < 5; i++)
		list2 = insert_last(list2, i * 11);
	printf("list2 = "); print_list(list2);
	delete_last(list2);
	printf("list2 = "); print_list(list2);


	//list3 = reverse(list2);
	//printf("list3 = "); print_list(list3);

	//concat(list1, list3);
	//printf("list1 = "); print_list(list1);

	if (is_in_list(list1, 10))
		printf("10 is in list1\n");
	else
		printf("10 is not is list1\n");

	printf("list1's length: %d\n", get_length(list1));

	printf("list1's total: %d\n", get_total(list1));

	list1 = delete_by_key(list1, 10);
	printf("list1 = "); print_list(list1);
	list1 = delete_by_key(list1, 100);
	printf("list1 = "); print_list(list1);

	list1 = insert_pos(list1, 1, 50);
	list1 = insert_pos(list1, 1, 40);
	printf("list1 = "); print_list(list1);

	list1 = delete_pos(list1, 0);
	printf("list1 = "); print_list(list1);
}