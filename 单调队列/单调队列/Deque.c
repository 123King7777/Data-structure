#define _CRT_SECURE_NO_WARNINGS 1
#include "Deque.h"
void DequeInit(Deque* s, int n)
{
	s->arr = calloc(n, sizeof(Deque));
	s->head = s->tail = 0;
}

//窗口[l,r)

//r位置元素加入窗口，修改窗口内最大值的更新结构、修改窗口内最小值的更新结构
void Dequepush(int* nums, int r, Deque* maxDeque, Deque* minDeque)
{
	// 每次对进入的元素进行判断，如果比当前最后的数字要小，则直接加入
	//如果加入的元素比某个位置大，则<=该元素的元素全部出队列，新元素加入队列

	//为什么？
	//单调队列始终维持着最大值的可能，队列中有比新元素还小的，那这些数显然已经没有成为最大值的可能
	//单调队列的队头可能随时移动，那么如果两个数一样大，一定是位置在前的元素先被淘汰，因此只记录最新的相等位置

	//numspmaxDeque[maxtail-1]]?  单调队列记录的是每个数据的下标，对于数组nums,其最大值位置在3，则
	//单调队列的队头一定记录的是3下标而不是最大值本身，因此需要根据下标找到数

	while (maxDeque->head < maxDeque->tail && nums[maxDeque->arr[maxDeque->tail - 1]] <= nums[r])
	{
		maxDeque->tail--;   
	}
	maxDeque->arr[maxDeque->tail++] = r;

	while (minDeque->head < minDeque->tail && nums[minDeque->arr[minDeque->tail - 1]] >= nums[r])
	{
		minDeque->tail--;
	}
	minDeque->arr[minDeque->tail++] = r;
}

//淘汰已经失效的队头元素
//在窗口移动过程中，一定会因为某种条件而缩小窗口去尝试新的可能，而这时维护的最大，最小队列的结构就可能改变
//当窗口左移时，意味着某些元素出了窗口，那么最大，最小队列所维护的最大，最小值就可能失效，因此需要更新
void Dequepop(Deque* maxDeque, Deque* minDeque, int l)
{
	// 因为有pop，说明l的值即将改变，因此在改变前，需要将队列也改变。
	//最大队列记录了最大值所在的下标，如果l移出的位置，正好是当前最大值所在的位置，那么head也需要移动
	//否则，不移动

	//head<tail保证队列中存在元素(因为范围是[l,r))
	while (maxDeque->head < maxDeque->tail && l == maxDeque->arr[maxDeque->head])
	{
		(maxDeque->head)++;   
	}

	while (minDeque->head < minDeque->tail&& l == minDeque->arr[minDeque->head])
	{
		(minDeque->head)++;       
	}
}

//该函数，首先求的新进入元素后的两个队列的最大最小值，之后根据这两个值对具体题目的要求进行判断，该函数
//具体问题具体分析
bool judge(int* nums, Deque* maxDeque, Deque* minDeque,int number)
{
	int max = maxDeque->head < maxDeque->tail ? getmax(number, nums[maxDeque->arr[maxDeque->head]]) : number;
	int min = minDeque->head < minDeque->tail ? getmin(number, nums[minDeque->arr[minDeque->head]]) : number;
}

int getmax(int x, int y)
{
	return x > y ? x : y;
}

int getmin(int x, int y)
{
	return x < y ? x : y;
}