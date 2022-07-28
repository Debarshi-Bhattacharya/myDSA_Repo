#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int mod=1e9+7;
	vector<vector<int>>grid(n,vector<int>(n,0));
	grid[0][0]=1;
	for(int i=0;i<n;i++)
	{
	    string str;
	    cin>>str;
	    for(int j=0;j<n;j++)
	    {
	        if(str[j]=='.')
	        {
	            if(i>0)
	                (grid[i][j]+=grid[i-1][j])%=mod;
	            if(j>0)
	                (grid[i][j]+=grid[i][j-1])%=mod;
	        }
	        else
	            grid[i][j]=0;
	    }
	}
	cout<<grid[n-1][n-1]<<endl;
}
