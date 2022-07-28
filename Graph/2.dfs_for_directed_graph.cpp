#include<bits/stdc++.h>
using namespace std;
stack<int>s;
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}
bool alltrue(vector<bool> vis)
{
	for (auto b : vis)
	{
		if (!b)
			return false;
	}
	return true;
}
void dfs(vector<bool> vis, vector<int> adj[])
{
	while (!alltrue(vis))
	{
		for (int i = 0; i < vis.size(); i++)
		{
			if (!vis[i])
				s.push(i);
			while (!s.empty())
			{
				int node = s.top();
				vis[node] = true;
				cout << node << " ";
				s.pop();
				for (auto it : adj[node])
				{
					if (!vis[it])
					{
						vis[it] = true;
						s.push(it);
					}
				}
			}
		}
	}
}
int main()
{
	int V, E, v, u;
	cin >> V >> E;
	vector<int>adj[V];
	vector<bool> vis;
	for (int i = 0; i < V; i++)
		vis[i] = false;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v;
		addEdge(adj, u, v);
	}
	for (int v = 0; v < V; ++v)
	{
		cout << v ;
		for (auto x : adj[v])
			cout << "-> " << x;
		cout << endl;
	}
	dfs(vis, adj);
}