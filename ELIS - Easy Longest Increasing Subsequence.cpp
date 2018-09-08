#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int n;
	cin>>n;
	int a[n];
	int lis[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	//initialize value for all indexes
	for(int i=0;i<n;i++)
		lis[i]=1;
	
	//compute optimized lis values in bottom up manner
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[i]>a[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
	int mval=-1;
	for(int i=0;i<n;i++)
		mval=max(mval,lis[i]);
	
	cout<<mval;
	
	return 0;
}
