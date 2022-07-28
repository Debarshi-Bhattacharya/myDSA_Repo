class Solution:
{
   public:
    // Function to detect cycle in an undirected graph.
    
    bool isCyclebfsUtil(int node,map<int,bool>&vis,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        vis[node]=true;
        q.push({node,-1})
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it: adj[node])
            {
                if(!vis[it])
                {
                    q.push({it,node});
                    vis[it]=true;
                }
                else if(it!=parent)
                    return true;
            }
            return false;
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        map<int,bool>vis;
        for(int v=0;v<V;v++)
        {
            vis[v]=false;
        }
        for(int v=0;v<V;v++)
        {
            if(!vis[v])
            {
                if(isCyclebfsUtil(v,vis,adj))
                    return true;
            }
        }
        return false;
    }
};