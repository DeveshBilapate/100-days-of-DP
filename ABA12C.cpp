#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,b;
		cin>>n>>k;
		b=k;
		int p[k+1];
		for(int i=1;i<=k;i++)
		cin>>p[i];
		
		int ans[k+1];
		for(int i=1;i<=k;i++)
		{
			ans[i]=p[i];
		}
		
		for(int i=2;i<=k;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(ans[i-j]==-1)
				continue;			
				ans[i]=min(ans[i],ans[i-j]+p[j]);
			}
		}
		
		if(k==0)
		cout<<"0\n";
		else
		cout<<ans[k]<<"\n";
	}
	
	return 0;
}
