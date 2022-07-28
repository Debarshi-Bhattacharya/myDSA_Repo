#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u,v,w;
    node(int first,int second,int weight)
    {
        u=first;
        v=second;
        w=weight;
    }
};
static bool comp(node a,node b)
{
    return a.w<b.w;
}
int findParent(int curr,vector<int> &parent)
{
    if(parent[curr]==curr) 
        return curr;
    return parent[curr]=findParent(parent[curr],parent);
}
void union_(int u,int v,vector<int> &rank,vector<int> &parent)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V,vector<vector<int>> adj[])
{
    vector<node>edge;
    for(int i=0;i<V;i++)
    {
        int u=i;
        for(auto &x:adj[u])
        {
            int v=x[0];
            int w=x[1];
            edge.push_back(node(u,v,w));
        }
        
    }
    sort(edge.begin(),edge.end(),comp);
    vector<int>parent(V);
    vector<int>rank(V,0);
    for(int i=0;i<V;i++)
    {
        parent[i]=i;
    }
    int cost=0;
    for(auto &it: edge)
    {
        if(findParent(it.u,parent)!=findParent(it.v,parent))
        {
            cost+=it.w;
            union_(it.u,it.v,rank,parent);
        }
    }
    return cost;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector<vector<int>> adj[V];
        int i=0;
        while(i++<E)
        {
            int u,v,w;
            cin>>u>>v>>w;
            vector<int>t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        cout<<spanningTree(V,adj)<<endl;
    }
    return 0;
}


/*sample input:
1
3 3
0 1 5
1 2 3
0 2 1

output: 4
*/