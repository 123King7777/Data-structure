#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//��ʼ������
void QueueInit(Queue* p)
{
	assert(p);
	p->head = NULL;
	p->tail = NULL;
}
//�����в�Ϊ�գ����ٶ���
void QueueDestory(Queue* p)
{
	assert(p);
	QNode* cur = p->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	p->head = p->tail = NULL;
}
//�����
void QueuePush(Queue* p, TypeData x)
{
	assert(p);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;
	if (p->head == NULL)
	{
		p->head = p->tail = newnode;
	}
	else
	{
		p->tail->next = newnode;
		p->tail = newnode;
	}
}
//������
void QueuePop(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	QNode* next = p->head->next;
	free(p->head);
	p->head = next;
	if (p->head == NULL)
	{
		p->tail = NULL;
	}
}
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* p)
{
	assert(p);
	return p->head == NULL;
}
//ȡ��ͷ����
TypeData QueueFront(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->head->data;
}
//ȡ��β����
TypeData QueueBack(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->tail->data;
}
//����г���
int QueueSize(Queue* p)
{
	assert(p);
	int count = 0;
	QNode* pq = p->head;
	while (pq)
	{
		count++;
		pq = pq->next;
	}
	return count;
}

