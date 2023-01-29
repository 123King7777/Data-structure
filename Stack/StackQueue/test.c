#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//void test()
//{
//	Stack s;
//	InitStack(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	StackPush(&s, 5);
//	StackPush(&s, 6);
//	while (!StackEmpty(&s))
//	{
//		printf("%d ", StackTop(&s));
//		StackPop(&s);
//	}
//	DestroyStack(&s);
//}
//
//typedef struct {
//    Stack minstack;
//    Stack aux;
//} MinStack;
//
//
////初始化最小栈
//MinStack* minStackCreate() {
//    MinStack* st = (MinStack*)malloc(sizeof(MinStack));
//    InitStack(&st->minstack);
//    InitStack(&st->aux);
//    return st;
//}
//
//void minStackPush(MinStack* obj, int val) {
//    if (!StackEmpty(&obj->aux))
//    {
//        if (StackTop(&obj->aux) >= val)
//            StackPush(&obj->aux, val);
//    }
//    else
//        StackPush(&obj->aux, val);
//    StackPush(&obj->minstack, val);
//}
//
//void minStackPop(MinStack* obj) {
//    if (StackTop(&obj->minstack) == StackTop(&obj->aux))
//    {
//        StackPop(&obj->minstack);
//        StackPop(&obj->aux);
//    }
//    else
//        StackPop(&obj->minstack);
//}
//
//int minStackTop(MinStack* obj) {
//    return StackTop(&obj->minstack);
//}
//
//int minStackGetMin(MinStack* obj) {
//    return StackTop(&obj->aux);
//}
//
//void minStackFree(MinStack* obj) {
//    DestroyStack(&obj->minstack);
//    DestroyStack(&obj->aux);
//    free(obj);
//}




int evalRPN(char** tokens, int tokensSize) {
    Stack s;
    InitStack(&s);
    for (int i = 0; i < tokensSize; i++)
    {
        if (tokens[i][0] == '+')
        {
            long a = StackTop(&s);
            StackPop(&s);
            long b = StackTop(&s);
            StackPop(&s);
            StackPush(&s, a + b);
        }
        else if ((tokens[i][0] == '-') && (strlen(tokens[i]) == 1))
        {
            long a = StackTop(&s);
            StackPop(&s);
            long b = StackTop(&s);
            StackPop(&s);
            StackPush(&s, b-a);
        }
        else if (tokens[i][0] == '*')
        {
            long a = StackTop(&s);
            StackPop(&s);
            long b = StackTop(&s);
            StackPop(&s);
            StackPush(&s, a * b);
        }
        else if (tokens[i][0] == '/')
        {
            long a = StackTop(&s);
            StackPop(&s);
            long b = StackTop(&s);
            StackPop(&s);
            StackPush(&s, b/a);
        }
        else
        {
            StackPush(&s,(long)atoi(tokens[i]));
        }
    }
    int ans =(int)StackTop(&s);
    DestroyStack(&s);
    return ans;
}

int main()
{
    char* a[] = { "-8","23","8","-","9","23","-","-","*","33","-8","/","+","38","-14","-","-","-7","32","-19","-","11","+","+","+","14","22","-","-","27","-9","-","+","31","+","-12","-11","-","-","14","+","30","+","37","30","-","+","-9","+","7","-","37","+","-5","13","/","-","19","-2","-19","12","+","-","23","+","-","-19","-","+","6","+","-17","+","17","+","5","36","+","-10","+","+","23","-8","-","-","18","-","31","-16","-","+","34","+","-6","+","24","-","22","-","-8","-","28","+","-12","+","39","28","-7","+","+","-14","5","+","5","+","10","+","+","+","-18","*","10","+","-5","11","-","6","+","-","-12","31","+","+","30","29","-","-","39","+","13","-8","-5","+","-","26","19","-","*","-","10","-","-20","5","+","+","0","-","28","-","19","/","28","+","-18","-","28","20","+","-5","-19","+","+","-","-12","-","3","-","6","-15","+","4","-","-","38","+","-9","-","38","-","12","-20","-","10","5","-15","-","-","-","+","-11","+","5","+","2","-","28","+","-9","-11","-","+","37","-","-17","31","-","2","+","+","-16","-12","-","-","12","+","34","-","15","+","8","+","17","-","2","-","33","+","-5","+","14","+","29","-","33","23","+","26","30","-","+","+","39","+","9","24","-","-","20","15","+","-","24","+","37","-","30","-1","-","+","34","+","-13","-","23","15","-","-","-5","-8","8","30","35","-9","22","+","-","-","36","-1","+","5","-","-","+","25","-","+","27","-","16","+","+","+","39","-","15","-","-3","+","5","-6","-","+","-6","-15","-7","-","+","/","13","-","18","+","4","+","29","+","-17","0","-6","-20","-17","+","12","-","+","-","+","+","-10","22","+","+","-11","-","-2","38","-","-","-6","+","0","-","-10","+","-4","-10","+","-","0","-","31","30","-","37","5","+","+","+","-15","+","38","4","-","-16","-17","+","+","+","38","-","27","-19","/","12","+","/" };
    int b=evalRPN(a, sizeof(a) / sizeof(a[0]));
    printf("%d", b);
    return 0;
}
