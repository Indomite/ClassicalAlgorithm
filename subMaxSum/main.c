#include<stdio.h>
#include<stdlib.h>
#define n 9
int a[n];
int MaxSum(int a[],int l,int r, int *sitel, int *siter)
{
    int c;  //�м�λ��
    int lsum,rsum,csum; //��ߡ��ұߡ��м�����
    if(l==r)
    {
        *sitel=l;
        *siter=l;
        return a[l];
    }
    else
    {
        c=(l+r)/2;
        //�ݹ����������ߵ�����ֶκ�
        lsum=MaxSum(a,l,c, sitel, siter);    //�������ֶκ�
        //��ߴ�ʱ��λ����ʱ����
        int ltemp_sitel, ltemp_siter;
        ltemp_sitel=*sitel;
        ltemp_siter=*siter;
        rsum=MaxSum(a,c+1,r, sitel, siter);  //�ұ�����ֶκ�
        //�ұߴ�ʱ��λ����ʱ����
        int rtemp_sitel, rtemp_siter;
        rtemp_sitel=*sitel;
        rtemp_siter=*siter;
        //�����м�����ֶκ�
        //����벿��
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
        //���Ұ벿��
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
        //�м�����
        csum=csuml+csumr;

        //λ��ȷ��
        if(csum>lsum)
            if(csum>rsum){  //�м����
                *sitel=templ;
                *siter=tempr;
                return csum;
            }else{  //�ұ����
                *sitel=rtemp_sitel;
                *siter=rtemp_siter;
                return rsum;
            }
        else if(lsum>rsum){ //������
            *sitel=ltemp_sitel;
            *siter=ltemp_siter;
            return lsum;
        }
    }
}

void input()
{
    int i;
    printf("������һ�����֣�");
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
    printf("����Ϊ:%4d\n",Sum);
    printf("�������͵���ֵ��");
    for(i=sitel; i<=siter; i++)
        printf("%4d",a[i]);
}
