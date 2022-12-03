#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	while (q.head)
	{
		printf("%d ", q.head->data);
		q.head = q.head->next;
	}
}

int main()
{
	test1();
}