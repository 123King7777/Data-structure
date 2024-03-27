#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//��άǰ׺�ͣ���Ƴ�ĳ�ֽṹ��֮��ÿ�����ά�������ⷶΧ�ϵ��ۼӺͶ���0(1)����
//1.���ɶ�άǰ׺������sum
//sum[i][j]:��ʾ���Ͻ�[0][0]�����½�(i,j)��Χ���ۼӺ�
//sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]

//2.��ѯ���Ͻ�(a,b)�����½�(c,d)���ۼӺ�
//sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1]

//3.ʵ������ʱ�������Ჹ0��0���������������жϣ���ϰ�߶���
//������0ʱ����Ҫע���Ӧ��ϵ



//��ʽһ��ֱ�Ӵ���ǰ׺������
typedef struct num{
    int** nums;     //��άǰ׺������
    int numsSize;   //����
}NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    //�����άǰ׺�ͽṹ��
    NumMatrix* sum = malloc(sizeof(NumMatrix));
    //��ʼ���д�С
    sum->nums = malloc(sizeof(int*) * (matrixSize + 1));
    sum->numsSize = matrixSize + 1;
    //��ʼ���д�С
    int colsize = (matrixColSize == NULL) ? 0 : *matrixColSize;
    for (int i = 0; i <= matrixSize; i++)  //ÿ����colsize+1��Ԫ��
    {
        sum->nums[i] = calloc(colsize + 1, sizeof(int)); //����Ԫ�س�ʼ��Ϊ0
    }

    //��matrix��������ݽ��п�����ע�����ڶ���0��0�У�����±�Ҫ��Ӧ
    for (int a = 1, c = 0; c < matrixSize; a++, c++)
    {
        for (int b = 1, d = 0; d < colsize; b++, d++)
        {
            sum->nums[a][b] = matrix[c][d];
        }
    }

    //����[0][0]~[i][j]���ۼӺ͡�������άǰ׺�͡�
    for (int i = 1; i <= matrixSize; i++)
    {
        for (int j = 1; j <= colsize; j++)
        {
            sum->nums[i][j] += sum->nums[i][j - 1] + sum->nums[i - 1][j] - sum->nums[i - 1][j - 1];
        }
    }
    return sum;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    //���ڶ���0��0�У����[c][d]��Ҫ�ƶ�
    row2++;
    col2++;
    return obj->nums[row2][col2] - obj->nums[row2][col1] - obj->nums[row1][col2] + obj->nums[row1][col1];
}


//��ʽ2����ԭ�����Ͻ��г�ʼ��ǰ׺������

//�ж��±��Ƿ�Ϸ�������Ϸ������ض�Ӧ�±�Ԫ�أ�����Ϊ0
int getnum(int** nums, int i, int j)
{
    return (i < 0 || j < 0) ? 0 : nums[i][j];
}

//��������[a][b]~[c][d]���ۼӺ�
//���a>c���������Ǹ�����Ϊ��0
//����ans=sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1]
int sum(int** nums, int a, int b, int c, int d)
{
    return a > c ? 0 : (getnum(nums, c, d) - getnum(nums, c, b - 1) - getnum(nums, a - 1, d) + getnum(nums, a - 1, b - 1));
}

//����"ǰ׺��"��ʵ��Ϊ[0][0]~[c][d]���ۼӺͣ�
void build(int** nums, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nums[i][j] += getnum(nums, i, j - 1) + getnum(nums, i - 1, j) - getnum(nums, i - 1, j - 1);
        }
    }
}

int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int m = (gridColSize == NULL) ? 0 : *gridColSize;
    //��ԭ�����޸�Ϊǰ׺������
    build(grid, n, m);                        //��ɳ�ʼ��

    //�������ݾ�����Ŀ����ʵ��
    
    //���[0][0]~[n-1][d-1]��ǰ׺��Ϊ0��˵����������ȫΪ0������������
    if (getnum(grid, n - 1, m - 1) == 0)
        return 0;
    int ans = 1;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            //[a][b]Ϊ���½ǣ�[c][d]Ϊ���½ǡ�kΪ���ܵı߳�
            //ÿ����������Ѱ�ҿ��ܵı߳���ͬʱ�߳�Ҳ��֮����
            //��ΪҪ��������һΪ�߽�������Σ����ֻ���Ǳȵ�ǰ�𰸸���ı߳�
            for (int c = a + ans, d = b + ans, k = ans + 1; c < n && d < m; c++, d++, k++)
            {
                if ((sum(grid, a, b, c, d) - sum(grid, a + 1, b + 1, c - 1, d - 1)) == ((k - 1) << 2))
                {
                    ans = k;
                }
            }
        }
    }
    return ans * ans;
}

int main()
{
    return 0;
}