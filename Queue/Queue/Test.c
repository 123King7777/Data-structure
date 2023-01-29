#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void test1()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
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
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {
    Queue* nullnode = &obj->q1;
    Queue* knownode = &obj->q2;
    if (!QueueEmpty(&obj->q1))
    {
        nullnode = &obj->q2;
        knownode = &obj->q1;
    }
    while (QueueSize(knownode) > 1)
    {
        QueuePush(nullnode, QueueFront(knownode));
        QueuePop(knownode);
    }
    int top = QueueFront(knownode);
    QueuePop(knownode);
    return top;
}


int main()
{
    test1();
    return 0;
}


