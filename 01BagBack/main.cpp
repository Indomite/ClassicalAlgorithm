#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define M 105

int n;      //��ʾ��Ʒ����
int W;      //��ʾ���ﳵ��������
double w[M];        //��ʾ��Ӧ��Ʒ����
double v[M];        //��ʾ��Ӧ��Ʒ��ֵ
bool x[M];              //�����ж��Ƿ���빺�ﳵ
double cw;             //��ǰ�Ž����ﳵ������
double cp;              //��ǰ�Ž����ﳵ�ܼ�ֵ
double bestp;           //��ǰ����ֵ
bool bestx[M];              //��ǰ���Ž�

double Bound(int i)         //�����Ͻ�
{
    int rp=0;
    while(i<=n)         //����ʣ����Ʒ������
    {
        rp+=v[i];
        i++;
    }
    return cp+rp;
}

void Backtrack(int t)       //���ݺ���
{
    if(t>n)         //�Ѿ�������Ҷ�ӽ��
    {
        for (int j=1;j<=n;j++)
        {
            bestx[j]=x[j];       //��¼���
        }
        bestp=cp;           //������ǰ����ֵ
        return;
    }

    if(cw+w[t]<=W)          //���������������չ��������������
    {
      x[t]=1;
      cw+=w[t];
      cp+=v[t];
      Backtrack(t+1);           //����
      cw-=w[t];
      cp-=v[t];
    }

    if(Bound(t+1)>bestp)            //��������޽�����������������
    {
      x[t]=0;
      Backtrack(t+1);           //����
    }
}

void Knapsack(double W,int n)
{
    //��ʼ��
    cw=0;
    cp=0;
    bestp=0;
    double sumw=0;
    double sumv=0;
    for (int i=1;i<=n;i++)
    {
        sumw+=w[i];
        sumv+=v[i];
    }
    if(sumw<=W)
    {
        bestp=sumv;
        cout << "�Ž����ﳵ����Ʒ����ֵ�ǣ�" << bestp << endl;
        return;
    }
    Backtrack(1);           //����
    cout << "���빺�ﳵ����Ʒ����ֵ�ǣ�" << bestp << endl;
    cout << "�Ž����ﳵ����Ʒ������ǣ�";
    for (int i=1;i<=n;i++)
    {
        if(bestx[i]==1)
        {
            cout << i << " " ;
        }
    }
    cout << endl;
}
int main()
{
    cout << "��������Ʒ�ĸ�����"  << endl;
    cin >>n;
    cout << "�����빺�ﳵ������W��" << endl;
    cin>>W;
    cout << "����������û����Ʒ������w�ͼ�ֵv���ÿո�ֿ�";
    for (int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
    Knapsack(W,n);
    return 0;
}
