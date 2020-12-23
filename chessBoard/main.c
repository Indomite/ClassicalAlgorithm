#include<stdio.h>
#define n 8     //n为2^k
int tr,tc;     //子棋盘的左上角第一个方格的横纵坐标
int dr,dc;     //特殊方格的横纵坐标
int size;
int board[n][n];
int tile=1;   //骨牌序号从1开始
void input()
{
    printf("输出棋盘长度：%d\n",n);
    printf("请输入特殊棋盘的位置dr,dc:");
    scanf("%d,%d",&dr,&dc);
    board[dr][dc]=0;
}
void chess(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)
        return;
    int t=tile++;
    int s=size/2;
    if(dr<tr+s && dc<tc+s)     //特殊方格在左上方
        chess(tr,tc,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s-1]=t;
        chess(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s && dc>=tc+s)     //特殊方格在右上方
        chess(tr,tc+s,dr,dc,s);
    else
    {
        board[tr+s-1][tc+s]=t;
        chess(tr,tc+s,tr+s-1,tc+s,s);
    }
    if(dr>=tr+s && dc<tc+s)     //特殊方格在左下方
        chess(tr+s,tc,dr,dc,s);
    else
    {
        board[tr+s][tc+s-1]=t;
        chess(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s && dc>=tc+s)     //特殊方格在右下方
        chess(tr+s,tc+s,dr,dc,s);
    else
    {
        board[tr+s][tc+s]=t;
        chess(tr+s,tc+s,tr+s,tc+s,s);
    }
}
void display()    //输出二维数组
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
