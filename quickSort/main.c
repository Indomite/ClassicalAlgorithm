#include <stdio.h>
#include <stdlib.h>

int RandomPartition(int a[],int l,int r)
{
    int i=rand()%(r-l+1)+l;
    int swap;
    swap=a[i];
    a[i]=a[l];
    a[l]=swap;
    return Partition(a,l,r);
}
int Partition(int a[],int l,int r)
{
    int i=l,j=r+1;
    int x=a[l];
    int swap;
    while(1)
    {
        while(a[++i]<x&&i<r);
        while(a[--j]>x);
        if(i>=j)
            break;
        swap=a[i];
        a[i]=a[j];
        a[j]=swap;
    }
    a[l]=a[j];
    a[j]=x;
    return j;
}

void RandomQuickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int q=RandomPartition(a,l,r);
        RandomQuickSort(a,l,q-1);
        RandomQuickSort(a,q+1,r);
    }
}
void main()
{
    int a[20]={21,5,85,91,80,99,48,39,75,67,45,56,47,48,51,65,45,52,35,45};
    int i;
    printf("数组初始顺序为：");
    for( i=0;i<20;i++)
        printf(" %d",a[i]);
    RandomQuickSort(a,0,19);
    printf("\n排序后数组顺序为：");
    for(i=0;i<20;i++)
        printf(" %d",a[i]);
}

