#include <iostream>
using namespace std;

/*
int find(int x, int y, int origx, int origy, int steps, int n)
{
	if(steps==n)
	{
		if(x==origx && y==origy) return 1;
		return 0;
	}
	
	if(steps>n)
	return 0;
	
  int p1= find(x+1,y,origx,origy,teps+1,n);
 // similarly find p2,p3,p4,p5,p6
  return p1+p2+p3+p+p5+p6;
	
}
*/

int main() {
	// your code goes here
	
	int dp[] = {1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	
	return 0;
}
