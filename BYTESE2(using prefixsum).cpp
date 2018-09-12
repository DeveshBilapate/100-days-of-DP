//prefix sum
#include <bits/stdc++.h>
using namespace std;
int a[10000001];

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,mxi=-1,mx=0,u,v;
		cin>>n;
		memset(a,0,sizeof a);
		for(int i=0;i<n;i++)
		{
			cin>>u>>v;
			a[u]++;
			a[v+1]--;
			mxi=max(mxi,v);
		}
		for(int i=1;i<mxi;i++)
		{
			a[i]+=a[i-1];
			mx=max(mx,a[i]);
		}
		cout<<mx<<"\n";
	}
	
	return 0;
}
