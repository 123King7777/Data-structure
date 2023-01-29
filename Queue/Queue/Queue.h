#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int TypeData;
//队列：先进先出的线性表，队尾插入数据，队头出数据

typedef struct QNode
{
	TypeData data;
	struct QNode* next;
}QNode;

typedef struct
{
	QNode* head;
	QNode* tail;   //定义头指针和尾指针
}Queue;

//初始化队列
void QueueInit(Queue* p);
//若队列存在，则摧毁队列
void QueueDestory(Queue* p);
//队尾插入数据
void QueuePush(Queue* p, TypeData x);
//队头删除数据
void QueuePop(Queue* p);
//求队列长度
int QueueSize(Queue* p);
//取队头数据
TypeData QueueFront(Queue* p);
//取队尾数据
TypeData QueueBack(Queue* p);
//判断队列是否为空
bool QueueEmpty(Queue* p);