#include <stdio.h>
#include <stdlib.h>
#define maxn 10
#define maxv 10

int max(int a,int b)
{
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    int N,V,f[maxn][maxv],c[maxn],v[maxn];
    printf("�����뱳����������Ʒ������\n");
    scanf("%d %d",&V,&N);
    printf("������������Ʒ����ͼ۸�\n");
    for(int i=1;i <= N;++i)
        scanf("%d %d",&v[i],&c[i]);
    for(int i=1;i <= N;++i)
        for(int j=1;j <= V;++j){
            f[i][j] = f[i-1][j];
            if(j >= v[i])
                f[i][j] = max(f[i-1][j],f[i-1][j-v[i]] + c[i]);
        }
    printf("����ֵ��%d\n",f[N][V]);
    return 0;
}
