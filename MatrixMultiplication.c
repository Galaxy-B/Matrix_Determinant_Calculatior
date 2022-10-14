#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int row1, row2, line1, line2, i, j, k, a, sum;
    row1 = line1 = 0;
    //为第一个矩阵赋值
    printf("请输入第一个目标矩阵的阶数：");
    scanf("%d%*c%d",&row1 ,&line1);
    int Matrix1[row1][line1];
    for (i = 0; i <= row1 - 1; i++)
    {
        printf("请输入第一个矩阵第%d行的元素:",i+1);
        for(j = 0; j <= line1 - 1; j++)
        {
            scanf("%d%*c",&a);
            Matrix1[i][j] = a;
        }
    }
    //为第二个矩阵赋值
    printf("请输入第二个目标矩阵的阶数：");
    scanf("%d%*c%d",&row2 ,&line2);
    int Matrix2[row2][line2];
    for (i = 0; i <= row2 - 1; i++)
    {
        printf("请输入第二个矩阵第%d行的元素:",i+1);
        for(j = 0; j <= line2 - 1; j++)
        {
            scanf("%d%*c",&a);
            Matrix2[i][j] = a;
        }
    }
    //检验输入的合法性
    if (line1 != row2)
    {
        printf("输入的目标矩阵无法进行乘法运算！");
        exit(0);
    }
    //进行矩阵乘法的运算
    int Matrix3[row1][line2];
    for (i = 0; i <= row1 - 1; i++)
    {
        for (j = 0; j <= line2 - 1; j++)
        {
            sum = 0;
            for (k = 0; k <= line1 - 1; k++)
            {
                sum += Matrix1[i][k] * Matrix2[k][j];
            }
            Matrix3[i][j] = sum;
        }
    }
    //打印最终计算结果的矩阵
    printf("目标矩阵乘法的计算结果为:\n");
    for (i = 0; i <= row1 - 1; i++)
    {
        for (j = 0; j <= line2 - 1; j++)
        {
            printf("%d\t",Matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}