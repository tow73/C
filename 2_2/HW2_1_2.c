#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
typedef struct {
	char name[100];
	char sex;
} element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;
typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;
// 초기화 함수
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// 포화 상태 검출 함수
int is_full(LinkedQueueType* q)
{
	return 0;
}
// 삽입 함수
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("메모리를 할당할 수 없습니다");
	else {
		temp->data = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp; // 순서 중요
			q->rear = temp;
		}
	}
}
// 삭제 함수
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q))
		printf("큐가 비어 있읍니다");
	else {
		item = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return item;
	}
}
void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%s ", p->data.name);
	printf("\n");
}
void match(LinkedQueueType* q1, LinkedQueueType* q2, element item)
{
	if (is_empty(q2)) {
		printf("아직 대상자가 없습니다. 기다려주십시요.\n");
		enqueue(q1, item);
	}
	else {
		enqueue(q1, item);
		printf("커플이 탄생했습니다! %s과 %s\n", q1->front->data.name, q2->front->data.name);
		dequeue(q1);
		dequeue(q2);
	}
}
int get_count(LinkedQueueType* q)
{
	QueueNode *temp = q->front;
	int count = 0;
	if (is_empty(q))
		return 0;
	else {
		while (temp != NULL) {
			count++;
			temp = temp->link;
		}
		return count;
	}
}
void main()
{
	LinkedQueueType male, female;
	element new;
	char button, sex;  //성별은 Queue에 저장할 필요 없음

	init(&male); init(&female);
	
	printf("미팅 주선 프로그램입니다.\n");
	do {
		printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit): ");
		scanf("%c", &button);

		if (button == 'i') {
			printf("이름을 입력: ");
			scanf("%s", new.name);
			rewind(stdin);
			printf("성별을 입력(m or f): ");
			scanf("%c", &new.sex);  //한 칸 띈 후 %c하면 rewind(stdin); 안 해도 됨

			if (new.sex == 'm')
				match(&male, &female, new);
			else if (new.sex == 'f')
				match(&female, &male, new);
		}
		else if (button == 'c') {
			printf("남성 대기자 %d명: ", get_count(&male));
			print_queue(&male);
			printf("여성 대기자 %d명: ", get_count(&female));
			print_queue(&female);
		}
		rewind(stdin);
	} while (button != 'q');
}