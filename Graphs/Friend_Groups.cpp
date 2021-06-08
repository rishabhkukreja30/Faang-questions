#include<bits/stdc++.h>
using namespace std;

void dfs_helper(unordered_map <int, list <int> > m , unordered_map <int, bool> &visited , int src) {
	visited[src] = true;

	for(auto child : m[src]) {
		if(!visited[child]) {
			dfs_helper(m,visited,child);
		}
	}
	return;
}


int dfs(unordered_map <int, list <int> > m , int n) {
	unordered_map <int, bool> visited;

	for(int i=0;i<n;i++) {
		visited[i] = false;
	}

	dfs_helper(m,visited,0);

	int components = 1;
	for(int i=1;i<n;i++) {
		if(!visited[i]) {
			dfs_helper(m,visited,i);
			components++;
		}
	}
	return components;
}


int friendCircles(vector <vector <int> > &M) {
	unordered_map <int, list <int> > m;
	int n = M.size();

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(M[i][j] == 1) {
				m[i].push_back(j);
			}
		}
	}

	return dfs(m,n);
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	return 0;
}