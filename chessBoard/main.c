#include<stdio.h>
#define n 8     //nΪ2^k
int tr,tc;     //�����̵����Ͻǵ�һ������ĺ�������
int dr,dc;     //���ⷽ��ĺ�������
int size;
int board[n][n];
int tile=1;   //������Ŵ�1��ʼ
void input()
{
    printf("������̳��ȣ�%d\n",n);
    printf("�������������̵�λ��dr,dc:");
    scanf("%d,%d",&dr,&dc);
    board[dr][dc]=0;
}
void chess(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)
        return;
    int t=tile++;
    int s=size/2;
    if(dr<tr+s && dc<tc+s)     //���ⷽ�������Ϸ�
        chess(tr,tc,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s-1]=t;
        chess(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s && dc>=tc+s)     //���ⷽ�������Ϸ�
        chess(tr,tc+s,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s]=t;
        chess(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s && dc<tc+s)     //���ⷽ�������·�
        chess(tr+s,tc,dr,dc,s);
    else
    {
        board[tr+s][tc+s-1]=t;
        chess(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s && dc>=tc+s)     //���ⷽ�������·�
        chess(tr+s,tc+s,dr,dc,s);
    else
    {
        board[tr+s][tc+s]=t;
        chess(tr+s,tc+s,tr+s,tc+s,s);
    }
}
void display()    //�����ά����
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d ",board[i][j]);
        }
        printf("\n\n");
    }
}
void main()
{
    input();
    chess(0,0,dr,dc,n);
    display();
}
