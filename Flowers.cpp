#include <iostream>
#define m 1000000007
using namespace std;
int dp[1000005];

int main() {
	// your code goes here
	
	int t,k;
	cin>>t>>k;
	dp[0]=1;
	for(int i=1;i<k;i++)
	dp[i]=1;
	
	for(int i=k;i<=1000000;i++)
	{
		dp[i]=(dp[i-1]+dp[i-k])%m;
	}
	
	for(int i=1;i<=100000;i++)
	{
		dp[i]=(dp[i]+dp[i-1])%m;
	}
	
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+m)%m<<"\n";
	}
	
	return 0;
}
