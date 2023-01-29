#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int TypeData;
//���У��Ƚ��ȳ������Ա���β�������ݣ���ͷ������

typedef struct QNode
{
	TypeData data;
	struct QNode* next;
}QNode;

typedef struct
{
	QNode* head;
	QNode* tail;   //����ͷָ���βָ��
}Queue;

//��ʼ������
void QueueInit(Queue* p);
//�����д��ڣ���ݻٶ���
void QueueDestory(Queue* p);
//��β��������
void QueuePush(Queue* p, TypeData x);
//��ͷɾ������
void QueuePop(Queue* p);
//����г���
int QueueSize(Queue* p);
//ȡ��ͷ����
TypeData QueueFront(Queue* p);
//ȡ��β����
TypeData QueueBack(Queue* p);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* p);