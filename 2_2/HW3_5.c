#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct DListNode {  //이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
void init(DListNode* phead) //이중 연결 리스트를 초기화
{
	phead->rlink = phead;
	phead->llink = phead;
}
void print_dlist(DListNode* phead) //이중 연결 리스트의 노드를 출력
{ 
	DListNode* p; 
	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-| |%d| |-> ", p->data);
	printf("\n"); 
}
void dinsert(DListNode *before, element data) //새로운 데이터를 노드 before의 오른쪽에 삽입한다.
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = before->rlink;  //1, 2 순서 바뀌어도 됨
	newnode->llink = before;
	before->rlink->llink = newnode; //3, 4 순서 바뀌면 안됨
	before->rlink = newnode;

}
void ddelete(DListNode* head, DListNode* removed) //노드 removed를 삭제한다
{
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink; //-> 1, 2 순서 바뀌어도 됨
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
int main(void) //이중 연결 리스트 테스트 프로그램
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	// 맨 앞에 노드를 삽입
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	// 맨 뒤에 노드를 삽입하려면?
	dinsert(head->llink, 99);
	print_dlist(head);
	printf("\n삭제 단계\n");
	// 맨 앞의 노드를 삭제
	ddelete(head, head->rlink);
	print_dlist(head);
	// 맨 뒤의 노드를 삭제하려면?
	ddelete(head, head->llink);
	print_dlist(head);

	printf("역순 출력: ");
	print_reverse_dlist(head);
	DListNode *p = search(head, 30);
	printf("search 30: ");
	if (p == NULL)
		printf("data 없음\n");
	else
		printf("data 있음\n");

	free(head);
	free(p);
	return 0;
}