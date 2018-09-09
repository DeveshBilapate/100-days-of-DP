#include <iostream>
using namespace std;

//recursive solution
int rknapsack(int w, int wt[], int val[], int n)
{
	//base case
	if(n==0 || w==0)
	return 0;
	
	// item cannot be included in the optimal solution
	if(wt[n-1]>w)
		return rknapsack(w,wt,val,n-1);
	
	else return max(val[n-1]+rknapsack(w-wt[n-1],wt,val,n-1),rknapsack(w,wt,val,n-1));
	
}

int knapsack(int W,int wt[], int val[], int n)
{
	int k[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(wt[i-1]<=w)
				k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
			else
				k[i][w]=k[i-1][w];
		}
	}
	return k[n][W];
}

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	while(n--)
	{
		int k,m;
		cin>>k>>m;
		//k max wt truck can handle
		int w[m],v[m];
		for(int i=0;i<m;i++)
		{
			cin>>w[i]>>v[i];
		}
		cout<<"Hey stupid robber, you can get "<<knapsack(k,w,v,m)<<".\n";
	}
	
	return 0;
}
