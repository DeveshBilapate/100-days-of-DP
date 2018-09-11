#include <bits/stdc++.h>
using namespace std;
string x,y;
int l[81][81];

//recursive imp
int lcsrecursive(int m, int n)
{
	if(m==0 || n==0)
	return 0;
	if(x[m-1]==y[n-1])
		return 1 + lcsrecursive(m-1,n-1);
	else
		return max(lcsrecursive(m,n-1),lcsrecursive(m-1,n));
}

int lcsdp(int m, int n)
{
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0)
			l[i][j]=0;
			else if(x[i-1]==y[j-1])
			l[i][j]=l[i-1][j-1]+1;
			else
			l[i][j]=max(l[i-1][j],l[i][j-1]);
		}
	}
	return l[m][n];
}

void lcsp(int m, int n)
{
	int index=l[m][n];
	string strlcs;
	int i=m,j=n;
	while(i>0 && j>0)
	{
		if(x[i-1]==y[j-1])
		{
			strlcs+=x[i-1];
			i--;j--;
		}
		else if(l[i-1][j]>l[i][j-1])
		i--;
		else
		j--;
	}
	reverse(strlcs.begin(),strlcs.end());
}

//returns set containing all lcss of x and y
set<string> findlcs(int m,int n)
{
	set<string>s;
	if(m==0 || n==0)
	{
		s.insert("");
		return s;
	}
	
	if(x[m-1]==y[n-1])
	{
		//recurse for x[0..m-2] & y[0..n-2] in the matrix
		set<string>tmp=findlcs(m-1,n-1);
		
		//append current character to all possible lcs of substrings of x[0..m-2] and y[0..n-2]
		for(string str:tmp)
			s.insert(str+x[m-1]);
	}
	//if last characters of x and y are not same
	else
	{
		if(l[m-1][n]>=l[m][n-1])
		s=findlcs(m-1,n);
		if(l[m][n-1]>=l[m-1][n])
		{
			set<string>tmp=findlcs(m,n-1);
			s.insert(tmp.begin(),tmp.end());
		}
	}
	
	return s;
}

int main() {
	// your code goes here
	
	int t;
	cin>>t;
	while(t--)
	{
		memset(l,0,sizeof l);
		cin>>x;
		cin>>y;
		lcsdp(x.size(),y.size());
//		lcsp(x.size(),y.size());
		set<string>s=findlcs(x.size(),y.size());
		vector<string>vs;
		for(auto it=s.begin();it!=s.end();it++)
		{
			vs.push_back(*it);
		}
		sort(vs.begin(),vs.end());
		for(auto it=vs.begin();it!=vs.end();it++)
		{
			cout<<*it<<"\n";
		}
		
//		cout<<"hjjdhjjhdhjhjd";
	}
	
	return 0;
}
