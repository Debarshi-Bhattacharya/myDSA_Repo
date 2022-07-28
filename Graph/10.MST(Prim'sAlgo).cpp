
#include<bits/stdc++.h>
using namespace std;



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        int parent[V];
        bool isMST[V];
        //make every element of key array as INF except element at index=0
        //every element of isMST as False and parent as -1
        for(int i=0;i<V;i++)
            key[i]=INT_MAX, parent[i]=-1, isMST[i]=false;
        key[0]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//(key_value,index)
        //find the index with minimum prossible key value which is also not a part of  the MST; initially it would be 0 always
        pq.push({0,0});//push(keyvalue,index)

        //we will always check for the index of the element which has least key value and also not part of the MST
        //the min-heap will always give us the element with minimum key value

        for(int i=0; i<V-1; i++)//we will have V-1 edges 
        //so we are going to iterate for that number of times
        {
            int u=pq.top().second;//index of the element with minimum key value 
            pq.pop();
            isMST[u]=true;//making it part of the MST
            for(auto &it: adj[u])// iterating over its adjacent nodes to update their key value
            {
                int v=it[0];
                int weight=it[1];
                if(!isMST[v] && key[v]>weight)// if a node is not part of MST yet and also it curr key value is also greater than the edge 
                //weight, we will not update its key value and will push into the min-heap with its key value and index
                {
                    parent[v]=u;//parent array will help us to print the MST
                    key[v]=weight;
                    pq.push({key[v],v});
                }
            }
        }
        //printing the mst
        for(int i=1;i<V;i++)
        {
            cout<<parent[i]<<"-->"<<i<<endl;
        }
        int pathSum=0;
        for(int v=0;v<V;v++)
        {
            pathSum+=key[v];
        }
        return pathSum;// the sum of weights of the edges of the Minimum Spanning Tree.
    }
};

