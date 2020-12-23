#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define M 105

int n;      //表示物品个数
int W;      //表示购物车总载重量
double w[M];        //表示对应物品重量
double v[M];        //表示对应物品价值
bool x[M];              //用来判断是否放入购物车
double cw;             //当前放进购物车总重量
double cp;              //当前放进购物车总价值
double bestp;           //当前最优值
bool bestx[M];              //当前最优解

double Bound(int i)         //计算上界
{
    int rp=0;
    while(i<=n)         //计算剩余物品重量和
    {
        rp+=v[i];
        i++;
    }
    return cp+rp;
}

void Backtrack(int t)       //回溯函数
{
    if(t>n)         //已经到达了叶子结点
    {
        for (int j=1;j<=n;j++)
        {
            bestx[j]=x[j];       //记录编号
        }
        bestp=cp;           //保留当前最优值
        return;
    }

    if(cw+w[t]<=W)          //如果满足条件，扩展并且搜索左子树
    {
      x[t]=1;
      cw+=w[t];
      cp+=v[t];
      Backtrack(t+1);           //回溯
      cw-=w[t];
      cp-=v[t];
    }

    if(Bound(t+1)>bestp)            //如果满足限界条件，搜索右子树
    {
      x[t]=0;
      Backtrack(t+1);           //回溯
    }
}

void Knapsack(double W,int n)
{
    //初始化
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
        cout << "放进购物车的物品最大价值是：" << bestp << endl;
        return;
    }
    Backtrack(1);           //回溯
    cout << "放入购物车的物品最大价值是：" << bestp << endl;
    cout << "放进购物车的物品的序号是：";
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
    cout << "请输入物品的个数："  << endl;
    cin >>n;
    cout << "请输入购物车的重量W：" << endl;
    cin>>W;
    cout << "请依次输入没个物品的重量w和价值v，用空格分开";
    for (int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
    Knapsack(W,n);
    return 0;
}
