#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct
{
	int* arr;
	int head;
	int tail;
}Deque;

void DequeInit(Deque* s,int n);

void Dequepush(int* nums, int r, Deque* maxDeque, Deque* minDeque);

void Dequepop(Deque* maxDeque,Deque* minDeque,int l);

bool judge(int* nums, Deque* maxDeque, Deque* minDeque);

int getmax(int x, int y);

int getmin(int x, int y);