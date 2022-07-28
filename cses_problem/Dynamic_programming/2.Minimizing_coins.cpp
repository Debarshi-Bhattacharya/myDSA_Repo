#include <bits/stdc++.h>
using namespace std;
void solve(int sum,vector<int>coin)
{
    int value[sum+1];
    value[0]=0;
    for(int x=1;x<=sum;x++)
    {
        value[x]=1e9;
        for(auto c:coin)
        {
            if((x-c)>=0)
            {
                value[x]=min(value[x-c]+1,value[x]);
            }
        }
    }
    cout<<(value[sum]==1e9?-1:value[sum])<<endl;
}
int main() {
	vector<int>coin;
	int sum,n,c;
	cin>>n>>sum;//no of coins
	for(int i=0;i<n;i++)
	{
	    cin>>c;
	    coin.push_back(c);
	}
	solve(sum,coin);
	return 0;
}
