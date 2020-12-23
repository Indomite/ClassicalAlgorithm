#include <stdio.h>
#include <stdlib.h>
#define max 10

int main()
{
    int a[max],s[max];
    int m,k,n;
    printf("输入数组长度：\n");
    scanf("%d",&n);
    printf("输入数组的值：\n");
    for(int i=0;i < n;i++){
        scanf("%d ",a[i]);
    }
    s[0] = 1;m = s[0];k = 0;
    for(int i=1;i < n;i++){
        if(a[i] > a[i-1]){
            s[i] = s[i] + s[i-1] + 1;
        }else{
            s[i] = 1;
        }
        if(s[i] > m){
            m = s[i];
            k=i;
        }
    }
    printf("最长连续上升子序列长度：%d\n",m);
    printf("最大连续上升子序列为：\n");
    for(int i=k-m+1;i < k;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
