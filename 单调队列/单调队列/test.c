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
int maxDeque[Max] = { 0 };     //�����������дӴ�С
int minDeque[Max] = { 0 };     //�����������д�С����


int maxhead = 0;     //����ͷ
int maxtail = 0;     //����β

int minhead = 0;
int mintail = 0;

//����[l,r)

//rλ��Ԫ�ؼ��봰�ڣ��޸Ĵ��������ֵ�ĸ��½ṹ���޸Ĵ�������Сֵ�ĸ��½ṹ
void push(int* nums, int right)
{
	//ÿ�ζԽ����Ԫ�ؽ����жϣ�����ȵ�ǰ��������ҪС����ֱ�Ӽ���
	//��������Ԫ�ر�ĳ��λ�ô���<=��Ԫ�ص�Ԫ��ȫ�������У���Ԫ�ؼ������
	
	//Ϊʲô��
	//��������ʼ��ά�������ֵ�Ŀ��ܣ��������б���Ԫ�ػ�С�ģ�����Щ����Ȼ�Ѿ�û�г�Ϊ���ֵ�Ŀ���
	//�������еĶ�ͷ������ʱ�ƶ�����ô���������һ����һ����λ����ǰ��Ԫ���ȱ���̭�����ֻ��¼���µ����λ��

	//numspmaxDeque[maxtail-1]]?  �������м�¼����ÿ�����ݵ��±꣬��������nums,�����ֵλ����3����
	//�������еĶ�ͷһ����¼����3�±���������ֵ���������Ҫ�����±��ҵ���

	while (maxhead < maxtail && nums[maxDeque[maxtail - 1]] <= nums[right]) 
	{
		maxtail--;      //��̭������Ԫ��С��������βǰ��
	}
	maxDeque[maxtail++] = right;     //��Ԫ�ؼ���

	//ά����Сֵ�Ķ���ͬ��
	while (minhead< mintail && nums[minDeque[mintail - 1]] >= nums[right]) 
	{
		mintail--;
	}
	minDeque[mintail++] = right;
}

//��̭�Ѿ�ʧЧ�Ķ�ͷԪ��
//�ڴ����ƶ������У�һ������Ϊĳ����������С����ȥ�����µĿ��ܣ�����ʱά���������С���еĽṹ�Ϳ��ܸı�
//����������ʱ����ζ��ĳЩԪ�س��˴��ڣ���ô�����С������ά���������Сֵ�Ϳ���ʧЧ�������Ҫ����
void pop(int left)
{
	//��Ϊ��pop��˵��l��ֵ�����ı䣬����ڸı�ǰ����Ҫ������Ҳ�ı䡣
	//�����м�¼�����ֵ���ڵ��±꣬���l�Ƴ���λ�ã������ǵ�ǰ���ֵ���ڵ�λ�ã���ôheadҲ��Ҫ�ƶ�
	//���򣬲��ƶ�
	if (maxhead < maxtail && maxDeque[maxhead] == left) 
	{
		maxhead++;
	}

	//��С����ͬ��
	if (minhead < mintail && minDeque[minhead] == left) 
	{
		minhead++;
	}
}

bool judge(int* nums, int number)
{
	//��Ԫ�ؼ���������������е���ֵ
	int MAX = maxhead < maxtail ? getmax(nums[maxDeque[maxhead]], number) : number;
	int MIN = maxhead < maxtail ? getmin(nums[minDeque[minhead]], number) : number;
	return;//�ж���Ԫ�ؼ�����Ƿ�����ĳ��������
}
int main()
{
	
	return 0;
}*/

