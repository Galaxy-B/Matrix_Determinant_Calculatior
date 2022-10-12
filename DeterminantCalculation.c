#include<stdio.h>
#include<math.h>

int rank;
int DetCalculate(int rank, int Determinant[rank][rank]);
int main(void)
{
    int i, j;
    printf("请输入目标行列式的阶数:");
    scanf("%d%*c",&rank);
    int Determinant[rank][rank];
    //对行列式进行赋值
    for (i = 0; i < rank; i++)
    {
        printf("请输入行列式第%d行的元素:",i + 1);
        for (j = 0; j < rank; j++)
        {
            scanf("%d%*c",&Determinant[i][j]);
        }
    }
    //对行列式进行计算
    printf("目标行列式的值为:%d",DetCalculate(rank, Determinant));
    return 0;
}
int DetCalculate(int rank, int Determinant[rank][rank])
{
    int i, j, k, det, sum = 0;
    //行列式阶数为1、2的情况
    if (rank == 2)      return Determinant[0][0] * Determinant[1][1] - Determinant[0][1] * Determinant[1][0];
    else if (rank == 1) return Determinant[0][0]; 
    //行列式阶数更高时采用按第一行展开的算法
    else
    {
        int Array[rank - 1][rank - 1];      //余子式
        for (i = 0; i < rank; i++)      
        {
            for (j = 0; j < rank - 1; j++)  //为余子式赋值
            {
                for (k = 0, det = 0; k < rank - 1; k++, det++)
                {
                    if (det == i)       det += 1;
                    Array[j][k] = Determinant[j + 1][det];
                }
            }
            sum += Determinant[0][i] * pow(-1 , i + 2) * DetCalculate(rank - 1, Array);
        }
        return sum;
    }
}