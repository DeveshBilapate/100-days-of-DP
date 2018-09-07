Problem link:  https://www.spoj.com/problems/GNY07H/
Reference: http://journeywithdp.blogspot.com/2018/07/way-to-solve-tiling-problems.html
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t,w;
	int f[10001],g[10001],h[10001];
	f[0]=1,f[1]=1,g[0]=1,g[1]=2,h[0]=1,h[1]=1;
	for(int i=2;i<=1000;i++)
	{
		f[i]=f[i-1]+f[i-2]+2*g[i-2]+h[i-2];
		g[i]=f[i]+g[i-1];
		h[i]=f[i]+h[i-2];
	}
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>w;
		cout<<i<<" "<<f[w]<<"\n";
	}
	
	return 0;
}
