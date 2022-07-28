class Solution:
{
   public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycleUtil(int node,map<int,bool>&vis,int parent,vector<int>adj[])
    {
        vis[node]=true;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(isCycleUtil(it,vis,node,adj))
                    return true;
            }
            else if(it!=parent)
            {
                return true;
            }
        }
        return false;
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
                if(isCycleUtil(v,vis,-1,adj))
                    return true;
            }
        }
        return false;
    }
};