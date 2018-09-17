#include <bits/stdc++.h>
#define ll  unsigned long int	
using namespace std;
ll dp[5004];

int main() {
	// your code goes here
	
	string s;
	cin>>s;
	
	while(s!="0")
	{
		memset(dp,0,sizeof dp);
		dp[0]=1;
		for(int i=1;i<s.length();i++)
		{
			int sd=s[i]-'0';
			int dd=(s[i-1]-'0')*10+s[i]-'0';
		//	cout<<"sd: "<<sd<<" dd: "<<dd<<"\n";
			if(s[i]-'0')
			dp[i]=dp[i-1];
			
			if(dd<=26 && dd>9)
			{
				if(i-2<0)
				dp[i]+=dp[0];
				else
				dp[i]+=dp[i-2];
			}
			
		}
		cout<<dp[s.length()-1]<<"\n";
		
/*		for(int i=0;i<s.length();i++)
		{
			cout<<dp[i]<<" ";
		}
		cout<<"\n";
*/		
		
		cin>>s;
	}
	
	return 0;
}
