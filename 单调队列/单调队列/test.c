#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

/*int getmax(int x, int y)
{
	return x > y ? x : y;
}
int getmin(int x, int y)
{
	return x < y ? x : y;
}
#define Max 100
int maxDeque[Max] = { 0 };     //单调减，队列从大到小
int minDeque[Max] = { 0 };     //单调增，队列从小到大


int maxhead = 0;     //队列头
int maxtail = 0;     //队列尾

int minhead = 0;
int mintail = 0;

//窗口[l,r)

//r位置元素加入窗口，修改窗口内最大值的更新结构、修改窗口内最小值的更新结构
void push(int* nums, int right)
{
	//每次对进入的元素进行判断，如果比当前最后的数字要小，则直接加入
	//如果加入的元素比某个位置大，则<=该元素的元素全部出队列，新元素加入队列
	
	//为什么？
	//单调队列始终维持着最大值的可能，队列中有比新元素还小的，那这些数显然已经没有成为最大值的可能
	//单调队列的队头可能随时移动，那么如果两个数一样大，一定是位置在前的元素先被淘汰，因此只记录最新的相等位置

	//numspmaxDeque[maxtail-1]]?  单调队列记录的是每个数据的下标，对于数组nums,其最大值位置在3，则
	//单调队列的队头一定记录的是3下标而不是最大值本身，因此需要根据下标找到数

	while (maxhead < maxtail && nums[maxDeque[maxtail - 1]] <= nums[right]) 
	{
		maxtail--;      //淘汰比新入元素小的数，队尾前移
	}
	maxDeque[maxtail++] = right;     //新元素加入

	//维护最小值的队列同理
	while (minhead< mintail && nums[minDeque[mintail - 1]] >= nums[right]) 
	{
		mintail--;
	}
	minDeque[mintail++] = right;
}

//淘汰已经失效的队头元素
//在窗口移动过程中，一定会因为某种条件而缩小窗口去尝试新的可能，而这时维护的最大，最小队列的结构就可能改变
//当窗口左移时，意味着某些元素出了窗口，那么最大，最小队列所维护的最大，最小值就可能失效，因此需要更新
void pop(int left)
{
	//因为有pop，说明l的值即将改变，因此在改变前，需要将队列也改变。
	//最大队列记录了最大值所在的下标，如果l移出的位置，正好是当前最大值所在的位置，那么head也需要移动
	//否则，不移动
	if (maxhead < maxtail && maxDeque[maxhead] == left) 
	{
		maxhead++;
	}

	//最小队列同理
	if (minhead < mintail && minDeque[minhead] == left) 
	{
		minhead++;
	}
}

bool judge(int* nums, int number)
{
	//新元素加入后，两个单调队列的最值
	int MAX = maxhead < maxtail ? getmax(nums[maxDeque[maxhead]], number) : number;
	int MIN = maxhead < maxtail ? getmin(nums[minDeque[minhead]], number) : number;
	return;//判断新元素加入后，是否满足某种条件。
}
int main()
{
	
	return 0;
}*/

