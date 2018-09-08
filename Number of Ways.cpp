#include <iostream>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	int a[n];
	ll s=0;
	for(int i=0;i<n;i++)
	cin>>a[i],s+=a[i];
	
	if(s%3!=0)
	return cout<<"0",0;
	else
	{
		ll ans=0,ls=0,p=0;
		for(int i=0;i<n-1;i++)
		{
			p+=a[i];
			if(p==((s/3)*2)) ans+=ls;
			if(p==(s/3)) ls++;
//			if(i==n-1) cout<<"p "<<p<<" ls "<<ls<<"\n\n";
		}
		cout<<ans;
	}
	
	return 0;
}
