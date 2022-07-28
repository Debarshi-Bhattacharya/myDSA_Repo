#include <bits/stdc++.h>
using namespace std;

// Methodolgy: as soon as the dfs call of a particular node ends we push it into the stack

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void topoUtil(int node, vector<int> adj[],stack<int>&s,vector<bool>&vis)
	{
	    vis[node]=true;
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	            topoUtil(it,adj,s,vis);
	    }
		//dfs call ends of a particular node and we pushed into the stack 
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    // code here
	    vector<int>ans;
	    stack<int>s;
	    vector<bool>vis(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            topoUtil(i,adj,s,vis);
	    }
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};

