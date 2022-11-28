#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void test()
{
	Stack s;
	InitStack(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	DestroyStack(&s);
}

int main()
{
	test();
	return 0;
}