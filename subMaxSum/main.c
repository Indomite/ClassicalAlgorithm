#include<stdio.h>
#include<stdlib.h>
#define n 9
int a[n];
int MaxSum(int a[],int l,int r, int *sitel, int *siter)
{
    int c;  //中间位置
    int lsum,rsum,csum; //左边、右边、中间最大和
    if(l==r)
    {
        *sitel=l;
        *siter=l;
        return a[l];
    }
    else
    {
        c=(l+r)/2;
        //递归求左右两边的最大字段和
        lsum=MaxSum(a,l,c, sitel, siter);    //左边最大字段和
        //左边大时的位置临时保存
        int ltemp_sitel, ltemp_siter;
        ltemp_sitel=*sitel;
        ltemp_siter=*siter;
        rsum=MaxSum(a,c+1,r, sitel, siter);  //右边最大字段和
        //右边大时的位置临时保存
        int rtemp_sitel, rtemp_siter;
        rtemp_sitel=*sitel;
        rtemp_siter=*siter;
        //计算中间最大字段和
        //求左半部份
        int i;
        int csuml=0,cleft=0;
        int templ=c;
        for(i=c;i>=l;i--)
        {
            cleft=cleft+a[i];
            if(cleft>csuml){
                csuml=cleft;
                templ=i;
            }
        }
        //求右半部份
        int j;
        int csumr=0,cright=0;
        int tempr=c;
        for(j=c+1;j<=r;j++)
        {
            cright=cright+a[j];
            if(cright>csumr){
                csumr=cright;
                tempr=j;
            }
        }
        //中间最大和
        csum=csuml+csumr;

        //位置确定
        if(csum>lsum)
            if(csum>rsum){  //中间最大
                *sitel=templ;
                *siter=tempr;
                return csum;
            }else{  //右边最大
                *sitel=rtemp_sitel;
                *siter=rtemp_siter;
                return rsum;
            }
        else if(lsum>rsum){ //左边最大
            *sitel=ltemp_sitel;
            *siter=ltemp_siter;
            return lsum;
        }
    }
}

void input()
{
    int i;
    printf("请输入一组数字：");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
}
void main()
{
    int Sum;
    int sitel=0;
    int siter=n-1;
    int i;
    input();
    Sum=MaxSum(a,0,n-1,&sitel, &siter);
    printf("最大和为:%4d\n",Sum);
    printf("构成最大和的数值：");
    for(i=sitel; i<=siter; i++)
        printf("%4d",a[i]);
}
