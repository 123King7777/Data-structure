#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

//初始化队列
void QueueInit(Queue* p)
{
	assert(p);
	p->head = NULL;
	p->tail = NULL;
}
//若队列不为空，销毁队列
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
//入队列
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
//出队列
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
//判断队列是否为空
bool QueueEmpty(Queue* p)
{
	assert(p);
	return p->head == NULL;
}
//取队头数据
TypeData QueueFront(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->head->data;
}
//取队尾数据
TypeData QueueBack(Queue* p)
{
	assert(p);
	assert(!QueueEmpty(p));
	return p->tail->data;
}
//求队列长度
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

