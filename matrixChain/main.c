#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 50

int p[MAX+1];             //存储各个矩阵的列数以及第一个矩阵的行数（作为第0个矩阵的列数）
int m[MAX][MAX];          //m[i][j]存储子问题的最优解
int s[MAX][MAX];           //s[i][j]存储子问题的最佳分割点
int n;                    //矩阵个数

 void matrix(int n,int m[][n],int s[][n],int p[])
{

    int i,j,k;
    for(i=0;i<n;i++)
        m[i][i]=0;                  //最小子问题仅含有一个矩阵 ，对角线全为0

    for(i=2;i<=n;i++)
        for(j=0;j<n-i+1;j++)
        {
            m[j][j+i-1]=INT_MAX;
            for(k=0;k<i-1;k++)
            {                                    //k代表分割点
                if(m[j][j+i-1]>m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i])
                {
                    m[j][j+i-1]=m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i];
                    s[j][j+i-1]=k;                           //记录分割点
                }
            }
        }
}

 void printmatrix(int l,int r)//递归打印输出
{
    if(l==r)
        printf("A%d",l);
    else{
        printf("(");
        printmatrix(l,l+s[l][r]);
        printmatrix(l+s[l][r]+1,r);
        printf(")");
    }
}
int main()
{
    int i;
    printf("请输入矩阵相乘的矩阵个数");
    scanf("%d",&n);
    printf("请依次输入矩阵的行和列（如A*B，A=20*30，B=30*40，即输入20 30 40)\n") ;
    for(i=0;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    matrix(n,m,s,p);
    printf("矩阵连乘最小次数\t%d\n",m[0][n-1]);
    printmatrix(0,n-1);
    printf("\n");
    return 0;
}
