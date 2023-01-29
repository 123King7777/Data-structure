#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef long SElemType;
typedef struct
{
	SElemType* a;
	int top;
	int capacity;
}Stack;

//ջ�ĳ�ʼ��
void InitStack(Stack* s);
//ջ������
void DestroyStack(Stack* s);
//����x��ջ��
void StackPush(Stack* s,SElemType x);
//ɾ��ջ��Ԫ��
void StackPop(Stack* s);
//��ջ�ǿգ�����ջ��Ԫ��x
SElemType StackTop(Stack* s);
//����ջ�Ĵ�С
int StackSize(Stack* s);
//�ж��Ƿ�Ϊ��ջ
bool StackEmpty(Stack* s);
//����ջ��Ԫ��


