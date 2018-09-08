#include <iostream>
using namespace std;

int n,m,x,y;
int p[22][22]={0};
int dp[22][22]={0};

int main() {
	// your code goes here
	
	cin>>n>>m;
	cin>>x>>y;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>p[i][j];

	
	dp[x][y]=p[x][y];
	
	//for row
//	FOR(i,y,m)
	for(int i=y;i<m;i++)
	{
		dp[x][i+1]=dp[x][i]-p[x][i+1];
	}
	
	for(int j=x;j<n;j++)
	{
		dp[j+1][y]=dp[j][y]-p[j+1][y];
	}
	
	for(int i=x;i<n;i++)
	{
		for(int j=y;j<m;j++)
		{
			int ns=
			dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])-p[i+1][j+1];
		}
	}
	
	if(dp[n][m]>=0)
		cout<<"Y "<<dp[n][m];
	else
		cout<<"N ";
	
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<p[i][j]<<" ";
		cout<<"\n";
	}
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<dp[i][j]<<" ";
		cout<<"\n";
	}
*/	
	
	return 0;
}
