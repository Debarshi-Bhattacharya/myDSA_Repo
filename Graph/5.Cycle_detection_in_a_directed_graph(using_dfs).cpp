 bool dfsUtil(int node,vector<int>adj[], vector<bool> &vis, vector<bool>&dfsStack)
    {
    //here we are keep track of the node in the visited or not(using the array vis) and the dfs call of a particular node is continuing or stopped(using the array
    // dfsStack), as we call dfs of a node we make both visited and dfsStack for that node as true, if dfs call ends for a node then we make its dfsStack false.
    //now while dfs call if we find that a adjacent node of current node is already visited then we check the adjacent node is true in the dfsStack or not, if so that 
    // means - its call isn't ended yet still we are finding it,therfore surely there is a cycle in the graph.
    if(!vis[node])
    {
        vis[node]=true;
        dfsStack[node]=true;
        //cout<<node;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfsUtil(it,adj,vis,dfsStack))
                    return true;
            }
            else if(dfsStack[it])
                return true;        
        }
    }         
    dfsStack[node]=false;
    return false;
}