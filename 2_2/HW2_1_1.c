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
void init(QueueType* q) //�ʱ�ȭ
{
	q->front = q->rear = 0;
}
int is_empty(QueueType* q) //���� ���� ����
{
	return (q->front == q->rear);
}
int is_full(QueueType* q) //��ȭ ���� ����
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, char* name) //����
{
	element item;
	strcpy(item.name, name);

	if (is_full(q))
		error("���� ����ڰ� �����ϴ�. ����ڰ� ��á���� ���ȸ�� �̿�");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}
element dequeue(QueueType* q) //����
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->queue[q->front];
	}
}
element peek(QueueType* q) //������
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
int get_count(QueueType* q) //����� �ο�
{
	if (is_empty(q))
		return 0;
	else if (is_full(q))
		return MAX_QUEUE_SIZE - 1;
	else
		return (q->rear) - (q->front);
}
void print_queue(QueueType* q) //����� ���
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
		printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", mq->queue[mq->front + 1].name, fq->queue[fq->front + 1].name);
		dequeue(mq);
		dequeue(fq);
	}
	else if (is_empty(mq) || is_empty(fq))
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
}
int main(void)
{
	QueueType male, female;
	element name[MAX_NAME_SIZE] = {0};
	char button, sex;

	init(&male);
	init(&female);

	printf("���� �ּ� ���α׷��Դϴ�.\n");

	while (1) {
		printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit): ");
		scanf("%c", &button);

		switch (button) {
		case 'i':
			printf("�̸��� �Է�: ");
			scanf("%s", name);
			rewind(stdin);
			printf("������ �Է�(m or f): ");
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
			printf("���� ����� %d��: ", get_count(&male));
			print_queue(&male);
			printf("���� ����� %d��: ", get_count(&female));
			print_queue(&female);
			break;
		case 'q':
			return 0;
		}
		rewind(stdin);
		/*if (button == 'i') {
			printf("�̸��� �Է�: ");
			scanf("%s", name);
			fflush(stdin);
			printf("������ �Է�(m or f): ");
			scanf("%c", &sex);

			if (sex == 'm')
				enqueue(&male, name);
			else if (sex == 'f')
				enqueue(&female, name);
		}
		else if (button == 'c') {
			printf("���� ����� %d��: ", get_count(&male));
			print_queue(&male);
			printf("���� ����� %d��: ", get_count(&female));
			print_queue(&female);
		}
		else if (button == 'q')
			break;*/
	}
}