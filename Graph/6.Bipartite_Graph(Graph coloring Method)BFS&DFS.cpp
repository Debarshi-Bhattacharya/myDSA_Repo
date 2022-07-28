class Solution {
public:
/*use color('0' & '1') to color the nodes, while bfs or dfs color the starting node by 1, then if the adjacent node of the current is not colored or visited, 
color it with '0'. If visited already then check if its color is different than its parent , if not return false as the graph is not bipartite*/


//using BFS//
    bool bfsUtil(vector<vector<int>>& graph,int node,int color[])
    {
        queue<int>qp;
        qp.push(node);
        int c=1;
        color[node]=c;
        while(!qp.empty())
        {
            int x=qp.front();
            qp.pop();
            for(auto it: graph[x])
            {
                if(color[it]==-1)
                {
                    qp.push(it);
                    color[it]=1-color[x];
                }
                else
                {
                    if(color[x]==color[it])
                        return false;
                }
            }       
        }
        return true;
    }

//using DFS
    bool dfsUtil(vector<vector<int>>& graph,int node,int color[])
    {
        if(color[node]==-1) 
            color[node]=1;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!dfsUtil(graph,it,color))
                    return false;
            }
            else
            {
                if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        memset(color,-1,sizeof(color));
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfsUtil(graph,i,color))
                    return false;
            }
        }
        return true;
    }
};