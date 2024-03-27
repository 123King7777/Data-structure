#define _CRT_SECURE_NO_WARNINGS 1
#include "Deque.h"
void DequeInit(Deque* s, int n)
{
	s->arr = calloc(n, sizeof(Deque));
	s->head = s->tail = 0;
}

//����[l,r)

//rλ��Ԫ�ؼ��봰�ڣ��޸Ĵ��������ֵ�ĸ��½ṹ���޸Ĵ�������Сֵ�ĸ��½ṹ
void Dequepush(int* nums, int r, Deque* maxDeque, Deque* minDeque)
{
	// ÿ�ζԽ����Ԫ�ؽ����жϣ�����ȵ�ǰ��������ҪС����ֱ�Ӽ���
	//��������Ԫ�ر�ĳ��λ�ô���<=��Ԫ�ص�Ԫ��ȫ�������У���Ԫ�ؼ������

	//Ϊʲô��
	//��������ʼ��ά�������ֵ�Ŀ��ܣ��������б���Ԫ�ػ�С�ģ�����Щ����Ȼ�Ѿ�û�г�Ϊ���ֵ�Ŀ���
	//�������еĶ�ͷ������ʱ�ƶ�����ô���������һ����һ����λ����ǰ��Ԫ���ȱ���̭�����ֻ��¼���µ����λ��

	//numspmaxDeque[maxtail-1]]?  �������м�¼����ÿ�����ݵ��±꣬��������nums,�����ֵλ����3����
	//�������еĶ�ͷһ����¼����3�±���������ֵ���������Ҫ�����±��ҵ���

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

//��̭�Ѿ�ʧЧ�Ķ�ͷԪ��
//�ڴ����ƶ������У�һ������Ϊĳ����������С����ȥ�����µĿ��ܣ�����ʱά���������С���еĽṹ�Ϳ��ܸı�
//����������ʱ����ζ��ĳЩԪ�س��˴��ڣ���ô�����С������ά���������Сֵ�Ϳ���ʧЧ�������Ҫ����
void Dequepop(Deque* maxDeque, Deque* minDeque, int l)
{
	// ��Ϊ��pop��˵��l��ֵ�����ı䣬����ڸı�ǰ����Ҫ������Ҳ�ı䡣
	//�����м�¼�����ֵ���ڵ��±꣬���l�Ƴ���λ�ã������ǵ�ǰ���ֵ���ڵ�λ�ã���ôheadҲ��Ҫ�ƶ�
	//���򣬲��ƶ�

	//head<tail��֤�����д���Ԫ��(��Ϊ��Χ��[l,r))
	while (maxDeque->head < maxDeque->tail && l == maxDeque->arr[maxDeque->head])
	{
		(maxDeque->head)++;   
	}

	while (minDeque->head < minDeque->tail&& l == minDeque->arr[minDeque->head])
	{
		(minDeque->head)++;       
	}
}

//�ú�������������½���Ԫ�غ���������е������Сֵ��֮�����������ֵ�Ծ�����Ŀ��Ҫ������жϣ��ú���
//��������������
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