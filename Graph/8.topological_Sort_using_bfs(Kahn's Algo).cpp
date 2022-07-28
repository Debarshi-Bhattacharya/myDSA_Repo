
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
		/* first calculate the inDegree of each node(if a node adjacent of other node then its inDegree should be increased by 1)*/
	    vector<int>inDegree(V,0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	            inDegree[it]++;
	    }
		// if a node has indegree of '0' push that into the queue
	    queue<int>qp;
	    for(int i=0;i<V;i++)
	    {
	        if(inDegree[i]==0)
	            qp.push(i);
	    }
	    // then perform BFS taking nodes one by one from queue, and while doing so reduce the indegree of the adjacent node by 1,
		// check if it is zero then push it into queue
	    vector<int>topo;
	    while(!qp.empty())
	    {
	        int node=qp.front();
	        qp.pop();
	        for(auto it:adj[node])
	        {
	            inDegree[it]--;
	            if(inDegree[it]==0)
	                qp.push(it);
	        }
	        topo.push_back(node);// as a node is completes its BFS ,it becomes a part of toposort
	    }
	   
	    return topo;
	}
};