#include<stdio.h>
#include<stdlib.h>

int a[1000];
int n;
int q(int n,int m)      //�󻮷ָ���
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

void result(int n,int k)    //������ֽ��   k�ݹ����
{
    int i;
	if(n==0)    //���ڣ��ֽ���ɣ�������
    {
		for(i=0;i<k-1;i++)
		{
			printf("%d+",a[i]);
		}
		printf("%d\n",a[i]);
	}
	else
    {
		for(i=n;i>0;i--)     //�ӵ�һ�㿪ʼ
		{
			if(k==0 || i<=a[k-1])    //����������a[k]>a[k+1]
            {
                a[k]=i;
                result(n-i,k+1);
            }
		}
	}
}
int main()
{
    printf("�����뻮�ֵ�����:");
    scanf("%d",&n);
    printf("���ָ���:%d\n",q(n,n));
    printf("���ֽ����ʾ:\n");
    result(n,0);
    return 0;
}
