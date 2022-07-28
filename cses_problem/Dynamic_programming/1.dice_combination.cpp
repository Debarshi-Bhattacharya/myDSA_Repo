#include <bits/stdc++.h>
using namespace std;
int main() {
	
	int target;
	cin>>target;
	int mod = 1e9+7;
	vector<int>dp(target+1,0);
	dp[0]=1;
	for(int x=1;x<=target;x++)
	{
	    for(int i=1;i<=6;i++)
	    {
	        if((x-i)>=0)
	            (dp[x]+=dp[x-i])%=mod;
	    }
	}
	cout<<dp[target]<<endl;
	return 0;
}
