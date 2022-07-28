#include <bits/stdc++.h>
using namespace std;
void solve(int sum,vector<int>coin)
{
    int value[sum+1];
    int first[sum+1];//storing the first element required the make a target sum(from 1 to given sum)
    value[0]=0;
    for(int x=1;x<=sum;x++)
    {
        value[x]=1e9;
        for(auto c:coin)
        {
            if((x-c)>=0 && value[x-c]+1<value[x])
            {
                value[x]=value[x-c]+1;
                first[x]=c;
            }
        }
    }
    ccout<<(value[sum]==1e9?-1:value[sum])<<endl;//minimum no of coins
    while(sum>0)
    {
        cout<<first[sum]<<endl;//the coins constituting the target sum in the optimal choice
        sum-=first[sum];
    }
}
int main() {
	vector<int>coin;
	int sum,n,c;
	cin>>n;//no of coins
	for(int i=0;i<n;i++)
	{
	    cin>>c;
	    coin.push_back(c);
	}
	cin>>sum;
	solve(sum,coin);
	return 0;
}
