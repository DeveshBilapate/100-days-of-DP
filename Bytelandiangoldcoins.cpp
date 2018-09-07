#include <bits/stdc++.h>
#define ut unsigned long long
using namespace std;
map<ut,ut>h;

ut MAX(ut a, ut b)
{
	if(a>=b)	return a;
	else	return b;
}

ut f(ut n)
{
	if(n<4) return n;
	
	ut r=h[n];
	if(r==0)
	{
		r=max(n,f(n/2)+f(n/3)+f(n/4));
		h[n]=r;
	}
	return r;
}

int main() {
	// your code goes here
	
	ut n;
	while(cin>>n)
	{
		cout<<f(n)<<"\n";
	}
	
	return 0;
}
