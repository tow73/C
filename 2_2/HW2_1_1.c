#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 100
typedef struct {
	char name[MAX_NAME_SIZE];
} element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}
void init(QueueType* q) //초기화
{
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) //공백 상태 검출
{
	return (q->front == q->rear);
}
int is_full(QueueType* q) //포화 상태 검출
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, char* name) //삽입
{
	element item;
	strcpy(item.name, name);

	if (is_full(q))
		error("아직 대상자가 없습니다. 대기자가 꽉찼으니 담기회를 이용");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
element dequeue(QueueType* q) //삭제
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}
element peek(QueueType* q) //엿보기
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
int get_count(QueueType* q) //대기자 인원
{
	if (is_empty(q))
		return 0;
	else if (is_full(q))
		return MAX_QUEUE_SIZE - 1;
	else
		return (q->rear) - (q->front);
}
void print_queue(QueueType* q) //대기자 출력
{
	int size = get_count(q);
	int index = (q->front + 1) % MAX_QUEUE_SIZE;

	for (int i = 0; i < size; i++) {
		printf("%s ", q->queue[index].name);
		index = (index + 1) % MAX_QUEUE_SIZE;
	}
	printf("\n");
}
void match(QueueType* mq, QueueType* fq)
{
	if (!is_empty(mq) && !is_empty(fq)) {
		printf("커플이 탄생했습니다! %s과 %s\n", mq->queue[mq->front + 1].name, fq->queue[fq->front + 1].name);
		dequeue(mq);
		dequeue(fq);
	}
	else if (is_empty(mq) || is_empty(fq))
		printf("아직 대상자가 없습니다. 기다려주십시요.\n");
}
int main(void)
{
	QueueType male, female;
	element name[MAX_NAME_SIZE] = {0};
	char button, sex;

	init(&male);
	init(&female);

	printf("미팅 주선 프로그램입니다.\n");

	while (1) {
		printf("i(nsert, 고객입력), c(heck, 대기자 체크), q(uit): ");
		scanf("%c", &button);

		switch (button) {
		case 'i':
			printf("이름을 입력: ");
			scanf("%s", name);
			rewind(stdin);
			printf("성별을 입력(m or f): ");
			scanf("%c", &sex);

			if (sex == 'm') { 
				enqueue(&male, name);
				if (!is_full(&male))
					match(&male, &female);
			}
			else if (sex == 'f') {
				enqueue(&female, name);
				if (!is_full(&female))
					match(&male, &female);
			}
			break;
		case 'c':
			printf("남성 대기자 %d명: ", get_count(&male));
			print_queue(&male);
			printf("여성 대기자 %d명: ", get_count(&female));
			print_queue(&female);
			break;
		case 'q':
			return 0;
		}
		rewind(stdin);
		/*if (button == 'i') {
			printf("이름을 입력: ");
			scanf("%s", name);
			fflush(stdin);
			printf("성별을 입력(m or f): ");
			scanf("%c", &sex);

			if (sex == 'm')
				enqueue(&male, name);
			else if (sex == 'f')
				enqueue(&female, name);
		}
		else if (button == 'c') {
			printf("남성 대기자 %d명: ", get_count(&male));
			print_queue(&male);
			printf("여성 대기자 %d명: ", get_count(&female));
			print_queue(&female);
		}
		else if (button == 'q')
			break;*/
	}
}