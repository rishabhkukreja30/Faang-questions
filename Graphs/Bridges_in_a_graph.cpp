#include<bits/stdc++.h>
using namespace std;


void dfs (int node, int parent, vector <int> &vis, vector <int> &tin, vector <int> &low, int &timer, vector <int> adj[]) {

	vis[node] = 1;
	tin[node] = low[node] = timer++;

	for(auto nbr : adj[node]) {
		if(nbr == parent) {
			continue;
		}

		if(!vis[nbr]) {
			dfs(nbr, node, vis, tin, low, timer, adj);
			low[node] = min(low[node], low[nbr]);
			if(low[nbr] > tin[node]) {
				cout<<node<<" " <<nbr <<endl;
			}
		}
		else {
			low[node] = min(low[node], tin[nbr]);
		}
	}
}


int main() {

	int n,m;
	cin>>n>>m;

	vector <int> adj[n];
	for(int i=0;i<m;i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector <int> tin(n, -1);
	vector <int> low(n, -1);
	vector <int> vis(n, 0);

	int timer = 0;
	for(int i=0;i<n;i++) {
		if(!vis[i]) {
			dfs(i, -1, vis, tin, low, timer, adj);
		}
	}

	return 0;
}