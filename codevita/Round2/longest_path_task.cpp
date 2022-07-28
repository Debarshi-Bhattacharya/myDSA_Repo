#include <bits/stdc++.h>
using namespace std;
int N=0;
bool isnum(char ch)
{
    if(ch>='0' && ch<='9')
        return true;
    return false;
}

void token_pro(string str,int n,map<int,vector<int>>&adj)
{
    int i=0;
    int temp;
    vector<int>v;
    while(i<n)
    {
        while(i<n && !isnum(str[i]))
        {
            i++;
        }
        temp=0;
        while(i<n && isnum(str[i]))
        {
            temp=10*temp+(str[i++]-'0');
        }
        if(temp!=0)
        {
            v.push_back(temp);
            N=max(N,temp);
        }
    }
    for(int i=1;i<v.size();i++)
        adj[v[i]].push_back(v[0]);
    
}
bool isCycleUtil(int node,map<int,vector<int>>adj,vector<bool> &vis, vector<bool>&dfsStack)
{
    if(!vis[node])
    {
        vis[node]=true;
        dfsStack[node]=true;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(isCycleUtil(it,adj,vis,dfsStack))
                    return true;
            }
            else if(dfsStack[it])
                return true;        
        }
    }         
    dfsStack[node]=false;
    return false;
}
void findPath(int node,vector<int> &dp,map<int,vector<int>>adj,vector<bool> &vis)
{
    vis[node]=true;
    dp[node]=0;
    for(auto it:adj[node])
    {
        if(!vis[it])
            findPath(it,dp,adj,vis);
        dp[node]=max(dp[node],1+dp[it]);
    }
}
int main() {
    string str;
    cin>>str;
    //tokenisation
    int n=str.length();
    istringstream ss(str);
    string token;
    map<int,vector<int>>adj;
    while(getline(ss, token, '}')) 
    {
        token_pro(token,token.length(),adj);
    }
    //checking cycle present or not
    vector<bool>vis(N+1,false);
    vector<bool>dfsStack(N+1,false);
    for(int i=1;i<=N;i++)
    {
        if(!vis[i])
        {
            if(isCycleUtil(i,adj,vis,dfsStack))
            {
                cout<<"error"<<endl;
                return 0;
            }      
        }
    }
    //longest path 
    for(int i=1;i<=N;i++)
        vis[i]=false;
    vector<int>dp(N+1);
    for(int i = 1; i <= N; i++){
		if(!vis[i]){
			findPath(i,dp,adj,vis);
		}
	}
	int ans = *max_element(dp.begin(),dp.end());
    cout<<ans+1<<endl;
    return 0;
}
