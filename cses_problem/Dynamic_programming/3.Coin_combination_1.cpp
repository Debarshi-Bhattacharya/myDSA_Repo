#include <bits/stdc++.h>
using namespace std;
int main() {
	int target,n;
	cin>>n>>target;
	int mod = 1e9+7;
	vector<int> coins(n);
  	for (int&v : coins) 
		cin >> v;
	vector<int>dp(target+1,0);
	dp[0]=1;
	for(int x=1;x<=target;x++)
	{
	    for(auto c: coins)
	    {
	        if((x-c)>=0)
	            (dp[x]+=dp[x-c])%=mod;
	    }
	}
	cout<<dp[target]<<endl;
	return 0;
}
