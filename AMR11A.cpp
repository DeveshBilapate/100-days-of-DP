#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		int s[r][c];
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cin>>s[i][j];
			}
		}
		s[r-1][c-1]=1;
		
		for(int i=c-2;i>=0;i--)
		{
			s[r-1][i]=s[r-1][i+1]-s[r-1][i];
			if(s[r-1][i]<=0)
				s[r-1][i]=1;
		}
		
		for(int i=r-2;i>=0;i--)
		{
			s[i][c-1]=s[i+1][c-1]-s[i][c-1];
			if(s[i][c-1]<=0)
				s[i][c-1]=1;
		}
		
		for(int i=r-2;i>=0;i--)
		{
			for(int j=c-2;j>=0;j--)
			{
				s[i][j]=min(s[i+1][j],s[i][j+1])-s[i][j];
				if(s[i][j]<=0)
					s[i][j]=1;
			}
		}
		
		cout<<s[0][0]<<"\n";
		
	}
	
	return 0;
}
