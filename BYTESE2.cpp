#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		vector<pair<int,int>>v;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
		int maxppl=0;
		for(int i=0;i<n;i++)
		{
			int count=1;
			for(int j=0;j<n;j++)
			{
				if(i==j) continue;
				if(v[j].first<v[i].first && v[j].second>v[i].first)
				count++;
			}
			maxppl=max(maxppl,count);
		}
		cout<<maxppl<<"\n";
	}
	
	return 0;
}
