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
    printf("请输入背包总量和物品数量：\n");
    scanf("%d %d",&V,&N);
    printf("请依次输入物品体积和价格：\n");
    for(int i=1;i <= N;++i)
        scanf("%d %d",&v[i],&c[i]);
    for(int i=1;i <= N;++i)
        for(int j=1;j <= V;++j){
            f[i][j] = f[i-1][j];
            if(j >= v[i])
                f[i][j] = max(f[i-1][j],f[i-1][j-v[i]] + c[i]);
        }
    printf("最大价值：%d\n",f[N][V]);
    return 0;
}
