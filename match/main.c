#include<stdio.h>
#include<stdlib.h>
#define num 5

int m[num][num]={{0,1,2,4,3},{0,2,1,3,4},{4,0,2,1,3},{2,1,3,0,4},{2,0,1,3,4}};   //������Ů����ƫ���̶�
int w[num][num]={{4,0,1,3,2},{3,1,2,0,4},{3,2,1,4,0},{0,1,3,2,4},{2,3,4,1,0}};   //Ů����������ƫ���̶�
int s1[num]={-1,-1,-1,-1,-1};    //�����Ƿ����  -1�� ����Ϊ���Ů�������
int s2[num]={-1,-1,-1,-1,-1};    //Ů���Ƿ����  -1�� ����Ϊ������������
void output() //�������ƫ�þ���
{
    printf("�У�0->����,1->����,2->����,3->���,4->�ܲ�\n");
    printf("Ů��0->����,1->����,2->С��,3->����,4->����\n");
    int i,j;
    printf("����ƫ�þ���\n");
    for(i=0;i<num;i++)
    {
        printf("��%d:",i);
        for(j=0;j<num;j++)
        {
            printf("% d",m[i][j]);
        }
        printf("\n");
    }
    printf("Ů��ƫ�þ���\n");
    for(i=0;i<num;i++)
    {
        printf("Ů%d:",i);
        for(j=0;j<num;j++)
        {
            printf("% d",w[i][j]);
        }
        printf("\n");
    }
}

void match()    //ƥ��
{
    int i,j,k;
    int old, now;
    for(i=0;i<num;i++){
        if(s1[i]==-1){    //������û����ƥ�����
            for(j=0;j<num;j++)
            {
                if(s2[m[i][j]]==-1){ //�������Ů��û����ԣ������
                    s1[i]=m[i][j];
                    s2[m[i][j]]=i;
                    break;
                }else{  //�������Ů�������
                    old=now=-1;
                    //Ѱ��Ů����������Ů�����Ƕ����б���±�
                    for(k=0;k<num;k++)
                        if(w[m[i][j]][k]==s2[m[i][j]])
                            old = k;
                    //Ѱ�ҵ�ǰ������Ů�����Ƕ����б���±�
                    for(k=0;k<num;k++)
                        if(w[m[i][j]][k]==i)
                            now = k;
                    if(old>now){ //���Ů������ƫ�����������򻻶���
                        s1[i]=m[i][j];  //��ǰ����
                        s2[m[i][j]]=i;
                        s1[w[m[i][j]][old]]=-1; //ǰ����
                        break;
                    }
                     //���Ů������ƫ���������������滻��һ��Ů��
                }
            }
        }
    }
    for(i=0;i<num;i++)    //�Ƿ����е�������������
    {
        if(s1[i]==-1){
            match();
            break;
        }
    }
}
void display()  //��������ɺ����Ů����
{
    int i;
    printf("man ���� woman\n");
    for(i=0;i<num;i++)
    {
        printf(" %d  ����  %d\n",i,s1[i]);
    }
}
int main()
{
    output();
    match();
    display();
}
