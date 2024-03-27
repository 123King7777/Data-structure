#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//二维前缀和：设计出某种结构，之后每次求二维数组任意范围上的累加和都是0(1)操作
//1.生成二维前缀和数组sum
//sum[i][j]:表示左上角[0][0]到右下角(i,j)范围的累加和
//sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]

//2.查询左上角(a,b)到右下角(c,d)的累加和
//sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1]

//3.实际做题时，往往会补0行0列来避免许多调节判断，依习惯而定
//但当补0时，需要注意对应关系



//形式一：直接创建前缀和数组
typedef struct num{
    int** nums;     //二维前缀和数组
    int numsSize;   //行数
}NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    //定义二维前缀和结构体
    NumMatrix* sum = malloc(sizeof(NumMatrix));
    //初始化行大小
    sum->nums = malloc(sizeof(int*) * (matrixSize + 1));
    sum->numsSize = matrixSize + 1;
    //初始化列大小
    int colsize = (matrixColSize == NULL) ? 0 : *matrixColSize;
    for (int i = 0; i <= matrixSize; i++)  //每行有colsize+1个元素
    {
        sum->nums[i] = calloc(colsize + 1, sizeof(int)); //所有元素初始化为0
    }

    //将matrix数组的内容进行拷贝，注意由于多了0行0列，因此下标要对应
    for (int a = 1, c = 0; c < matrixSize; a++, c++)
    {
        for (int b = 1, d = 0; d < colsize; b++, d++)
        {
            sum->nums[a][b] = matrix[c][d];
        }
    }

    //计算[0][0]~[i][j]的累加和——“二维前缀和”
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
    //由于多了0行0列，因此[c][d]需要移动
    row2++;
    col2++;
    return obj->nums[row2][col2] - obj->nums[row2][col1] - obj->nums[row1][col2] + obj->nums[row1][col1];
}


//形式2：在原数组上进行初始化前缀和数组

//判断下标是否合法，如果合法，返回对应下标元素，否则为0
int getnum(int** nums, int i, int j)
{
    return (i < 0 || j < 0) ? 0 : nums[i][j];
}

//计算区域[a][b]~[c][d]的累加和
//如果a>c，则该区域非负，认为是0
//否则，ans=sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1]
int sum(int** nums, int a, int b, int c, int d)
{
    return a > c ? 0 : (getnum(nums, c, d) - getnum(nums, c, b - 1) - getnum(nums, a - 1, d) + getnum(nums, a - 1, b - 1));
}

//计算"前缀和"（实际为[0][0]~[c][d]的累加和）
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
    //将原数组修改为前缀和数组
    build(grid, n, m);                        //完成初始化

    //以下内容具体题目具体实现
    
    //如果[0][0]~[n-1][d-1]的前缀和为0，说明整个数组全为0，不符合题意
    if (getnum(grid, n - 1, m - 1) == 0)
        return 0;
    int ans = 1;
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            //[a][b]为左下角，[c][d]为右下角。k为可能的边长
            //每次向下增大寻找可能的边长，同时边长也随之增大
            //因为要求最大的以一为边界的正方形，因此只考虑比当前答案更大的边长
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