#include<stdio.h>
#include<stdlib.h>

int a[1000];
int n;
int q(int n,int m)      //求划分个数
{
    if((n<1)||(m<1))
        return 0;
    if((n==1)||(m==1))
        return 1;
    if(n<m)
        return q(n,n);
    if(n==m)
        return q(n,n-1)+1;
    else
        return q(n,m-1)+q(n-m,m);
}

void result(int n,int k)    //输出划分结果   k递归层数
{
    int i;
	if(n==0)    //出口：分解完成，输出结果
    {
		for(i=0;i<k-1;i++)
		{
			printf("%d+",a[i]);
		}
		printf("%d\n",a[i]);
	}
	else
    {
		for(i=n;i>0;i--)     //从第一层开始
		{
			if(k==0 || i<=a[k-1])    //划分条件：a[k]>a[k+1]
            {
                a[k]=i;
                result(n-i,k+1);
            }
		}
	}
}
int main()
{
    printf("请输入划分的整数:");
    scanf("%d",&n);
    printf("划分个数:%d\n",q(n,n));
    printf("划分结果表示:\n");
    result(n,0);
    return 0;
}
