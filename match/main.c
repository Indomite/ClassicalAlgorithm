#include<stdio.h>
#include<stdlib.h>
#define num 5

int m[num][num]={{0,1,2,4,3},{0,2,1,3,4},{4,0,2,1,3},{2,1,3,0,4},{2,0,1,3,4}};   //男生对女生的偏爱程度
int w[num][num]={{4,0,1,3,2},{3,1,2,0,4},{3,2,1,4,0},{0,1,3,2,4},{2,3,4,1,0}};   //女生对男生的偏爱程度
int s1[num]={-1,-1,-1,-1,-1};    //男生是否配对  -1否 其它为配对女生的序号
int s2[num]={-1,-1,-1,-1,-1};    //女生是否配对  -1否 其它为配对男生的序号
void output() //输出两个偏好矩阵
{
    printf("男：0->吕布,1->刘备,2->孔明,3->周瑜,4->曹操\n");
    printf("女：0->貂蝉,1->大乔,2->小乔,3->尚香,4->阿丑\n");
    int i,j;
    printf("男生偏好矩阵：\n");
    for(i=0;i<num;i++)
    {
        printf("男%d:",i);
        for(j=0;j<num;j++)
        {
            printf("% d",m[i][j]);
        }
        printf("\n");
    }
    printf("女生偏好矩阵：\n");
    for(i=0;i<num;i++)
    {
        printf("女%d:",i);
        for(j=0;j<num;j++)
        {
            printf("% d",w[i][j]);
        }
        printf("\n");
    }
}

void match()    //匹配
{
    int i,j,k;
    int old, now;
    for(i=0;i<num;i++){
        if(s1[i]==-1){    //该男生没有有匹配对象
            for(j=0;j<num;j++)
            {
                if(s2[m[i][j]]==-1){ //如果心仪女神没有配对，则配对
                    s1[i]=m[i][j];
                    s2[m[i][j]]=i;
                    break;
                }else{  //如果心仪女神有配对
                    old=now=-1;
                    //寻找女生现男友在女生心仪对象列表的下标
                    for(k=0;k<num;k++)
                        if(w[m[i][j]][k]==s2[m[i][j]])
                            old = k;
                    //寻找当前男生在女生心仪对象列表的下标
                    for(k=0;k<num;k++)
                        if(w[m[i][j]][k]==i)
                            now = k;
                    if(old>now){ //如果女生更加偏爱该男生，则换对象
                        s1[i]=m[i][j];  //当前男生
                        s2[m[i][j]]=i;
                        s1[w[m[i][j]][old]]=-1; //前男友
                        break;
                    }
                     //如果女生更加偏爱现在男生，则替换下一个女生
                }
            }
        }
    }
    for(i=0;i<num;i++)    //是否所有的男生都配对完成
    {
        if(s1[i]==-1){
            match();
            break;
        }
    }
}
void display()  //输出配对完成后的男女搭配
{
    int i;
    printf("man —— woman\n");
    for(i=0;i<num;i++)
    {
        printf(" %d  ——  %d\n",i,s1[i]);
    }
}
int main()
{
    output();
    match();
    display();
}
