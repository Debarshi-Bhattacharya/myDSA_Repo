#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int source)
    {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	    vector<int> distTo(V,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
    	distTo[source] = 0;
    	pq.push(make_pair(0,source));	// (dist,from)
    	
    	while(!pq.empty()){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
    		
		for(auto &it: adj[prev]){
			int next = it[0];
			int nextDist = it[1];
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
    	}
		return distTo;
    		
    }
};


