#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void InitStack(Stack* s)
{
	assert(s);
	s->a = NULL;
	s->capacity = 0;
	s->top = -1;
}

void DestroyStack(Stack* s)
{
	assert(s);
	free(s->a);
	s->a = NULL;
	s->capacity = 0;
	s->top = -1;
}

void StackPush(Stack* s, SElemType x)
{
	assert(s);
	if (s->top == s->capacity - 1)
	{
		int newcapacity = (s->capacity > 0) ? 2 * (s->capacity) : 4;
		SElemType* p = realloc(s->a,sizeof(SElemType) * newcapacity);
		if (p == NULL)
		{
			printf("realloc fail!");
			exit(-1);
		}
		s->a = p;
		s->capacity =newcapacity;
	}
	s->top++;
	s->a[s->top] = x;
}

void StackPop(Stack* s)
{
	assert(s);
	assert(s->top > -1);
	s->top--;
}

SElemType StackTop(Stack* s)
{
	assert(s);
	assert(s->top > -1);
	return (s->a[s->top]);
}

int StackSize(Stack* s)
{
	assert(s);
	assert(s->top >= -1);
	return s->top + 1;
}

bool StackEmpty(Stack* s)
{
	assert(s);
	return s->top == -1;
}