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

//栈的初始化
void InitStack(Stack* s);
//栈的销毁
void DestroyStack(Stack* s);
//插入x到栈中
void StackPush(Stack* s,SElemType x);
//删除栈顶元素
void StackPop(Stack* s);
//若栈非空，返回栈顶元素x
SElemType StackTop(Stack* s);
//返回栈的大小
int StackSize(Stack* s);
//判断是否为空栈
bool StackEmpty(Stack* s);
//返回栈底元素


