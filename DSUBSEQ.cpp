#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[100005];
int previous[30];

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
//		int dp[s.length()+1],previous[27]={0};
		memset(dp,0,sizeof dp);
		memset(previous,-1,sizeof previous);
		dp[0]=1;
		
		for(int i=0;i<s.length();i++)
		{
			dp[i+1]=(dp[i]*2)%mod;
			if(previous[s[i]-65]!=-1)
			{
				dp[i+1]=(dp[i+1]-dp[previous[s[i]-65]]+mod)%mod;
			}
			previous[s[i]-65]=i;
		}
		
/*		for(int i=0;i<=s.length();i++)
		cout<<dp[i]<<" ";
		cout<<"\n";
		
		for(int i=0;i<27;i++)
		cout<<previous[i]<<" ";
		cout<<"\n";
*/		
		
		cout<<dp[s.length()]<<"\n";
	}
	
	return 0;
}
