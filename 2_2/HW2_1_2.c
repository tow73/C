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
// �ʱ�ȭ �Լ�
void init(LinkedQueueType* q)
{
	q->front = q->rear = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q)
{
	return 0;
}
// ���� �Լ�
void enqueue(LinkedQueueType* q, element item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	if (temp == NULL)
		printf("�޸𸮸� �Ҵ��� �� �����ϴ�");
	else {
		temp->data = item;
		temp->link = NULL;
		if (is_empty(q)) {
			q->front = temp;
			q->rear = temp;
		}
		else {
			q->rear->link = temp; // ���� �߿�
			q->rear = temp;
		}
	}
}
// ���� �Լ�
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q))
		printf("ť�� ��� �����ϴ�");
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
		printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
		enqueue(q1, item);
	}
	else {
		enqueue(q1, item);
		printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", q1->front->data.name, q2->front->data.name);
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
	char button, sex;  //������ Queue�� ������ �ʿ� ����

	init(&male); init(&female);
	
	printf("���� �ּ� ���α׷��Դϴ�.\n");
	do {
		printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit): ");
		scanf("%c", &button);

		if (button == 'i') {
			printf("�̸��� �Է�: ");
			scanf("%s", new.name);
			rewind(stdin);
			printf("������ �Է�(m or f): ");
			scanf("%c", &new.sex);  //�� ĭ �� �� %c�ϸ� rewind(stdin); �� �ص� ��

			if (new.sex == 'm')
				match(&male, &female, new);
			else if (new.sex == 'f')
				match(&female, &male, new);
		}
		else if (button == 'c') {
			printf("���� ����� %d��: ", get_count(&male));
			print_queue(&male);
			printf("���� ����� %d��: ", get_count(&female));
			print_queue(&female);
		}
		rewind(stdin);
	} while (button != 'q');
}