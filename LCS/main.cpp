#include <iostream>
using namespace std;
#define N 100
int n,m;
char S1[N],S2[N];
int dp[N][N];
int b[N][N];

void LCSLength()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++){
			dp[i][0]=0;
			dp[0][j]=0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(S1[i]==S2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(dp[i-1][j]>dp[i][j-1]){
				dp[i][j]=dp[i-1][j];
				b[i][j]=2;
			}
			else{
				dp[i][j]=dp[i][j-1];
				b[i][j]=3;
			}
		}
}

void LCS(int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==1){
		LCS(i-1,j-1);
		cout<<S1[i]<<" ";//S2[j]
	}
	else if(b[i][j]==2)
		LCS(i-1,j);
	else
		LCS(i,j-1);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>S1[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>S2[i];
	LCSLength();
	cout<<"最长公共子序列长度是："<<dp[n][m]<<endl;
	cout<<"最长公共子序列是：";
	LCS(n,m);
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
}
