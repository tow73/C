#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct DListNode {  //���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
void init(DListNode* phead) //���� ���� ����Ʈ�� �ʱ�ȭ
{
	phead->rlink = phead;
	phead->llink = phead;
}
void print_dlist(DListNode* phead) //���� ���� ����Ʈ�� ��带 ���
{ 
	DListNode* p; 
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n"); 
}
void dinsert(DListNode *before, element data) //���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = before->rlink;  //1, 2 ���� �ٲ� ��
	newnode->llink = before;
	before->rlink->llink = newnode; //3, 4 ���� �ٲ�� �ȵ�
	before->rlink = newnode;

}
void ddelete(DListNode* head, DListNode* removed) //��� removed�� �����Ѵ�
{
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink; //-> 1, 2 ���� �ٲ� ��
	removed->rlink->llink = removed->llink;
	free(removed);
}
void print_reverse_dlist(DListNode* head)
{
	DListNode *p;
	for (p = head->llink; p != head; p = p->llink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n");
}
DListNode* search(DListNode* head, element data)
{
	DListNode *p;
	for (p = head->rlink; p != head; p = p->rlink)
		if (p->data == data)
			return p;
	return NULL;
}
int main(void) //���� ���� ����Ʈ �׽�Ʈ ���α׷�
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");
	// �� �տ� ��带 ����
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	// �� �ڿ� ��带 �����Ϸ���?
	dinsert(head->llink, 99);
	print_dlist(head);
	printf("\n���� �ܰ�\n");
	// �� ���� ��带 ����
	ddelete(head, head->rlink);
	print_dlist(head);
	// �� ���� ��带 �����Ϸ���?
	ddelete(head, head->llink);
	print_dlist(head);

	printf("���� ���: ");
	print_reverse_dlist(head);
	DListNode *p = search(head, 30);
	printf("search 30: ");
	if (p == NULL)
		printf("data ����\n");
	else
		printf("data ����\n");

	free(head);
	free(p);
	return 0;
}