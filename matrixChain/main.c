#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 50

int p[MAX+1];             //�洢��������������Լ���һ���������������Ϊ��0�������������
int m[MAX][MAX];          //m[i][j]�洢����������Ž�
int s[MAX][MAX];           //s[i][j]�洢���������ѷָ��
int n;                    //�������

 void matrix(int n,int m[][n],int s[][n],int p[])
{

    int i,j,k;
    for(i=0;i<n;i++)
        m[i][i]=0;                  //��С�����������һ������ ���Խ���ȫΪ0

    for(i=2;i<=n;i++)
        for(j=0;j<n-i+1;j++)
        {
            m[j][j+i-1]=INT_MAX;
            for(k=0;k<i-1;k++)
            {                                    //k����ָ��
                if(m[j][j+i-1]>m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i])
                {
                    m[j][j+i-1]=m[j][j+k]+m[j+k+1][j+i-1]+p[j]*p[j+k+1]*p[j+i];
                    s[j][j+i-1]=k;                           //��¼�ָ��
                }
            }
        }
}

 void printmatrix(int l,int r)//�ݹ��ӡ���
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
    printf("�����������˵ľ������");
    scanf("%d",&n);
    printf("���������������к��У���A*B��A=20*30��B=30*40��������20 30 40)\n") ;
    for(i=0;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    matrix(n,m,s,p);
    printf("����������С����\t%d\n",m[0][n-1]);
    printmatrix(0,n-1);
    printf("\n");
    return 0;
}
