#include <iostream>
#define mod 1000000007
using namespace std;
int dp[2015][2015];

int main() {
	// your code goes here
	
	int n,k;
	cin>>n>>k;
	int ans=0;
	dp[1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				//dp[i][l] l is length and ends with i
				for(int l=1;l<=k;l++)
					dp[i][l]=(dp[i][l]+dp[j][l-1])%mod;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[i][k])%mod;
	}
	cout<<ans<<"\n";
	
	return 0;
}
