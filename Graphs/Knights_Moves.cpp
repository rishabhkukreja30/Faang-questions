#include<bits/stdc++.h>
using namespace std;

class graph {

	unordered_map <pair <int, int> , list <pair <int, int> >> m1;

public:
	void addEdge(int i, int j, int n, int m) {

		pair <int, int> p = make_pair(i,j);

		if(i+2 < n) {
			if(j+1 < m) {
				m1[p].push_back(make_pair(i+2,j+1));
			}
			if(j-1 >= 0) {
				m1[p].push_back(make_pair(i+2,j-1));
			}
		}

		if(i-2 >= 0) {
			if(j+1 < m) {
				m1[p].push_back(make_pair(i-2,j+1));
			}
			if(j-1 >= 0) {
				m1[p].push_back(make_pair(i-2,j-1));
			}			
		}

		if(i+1 < n) {
			if(j+2 < m) {
				m1[p].push_back(make_pair(i+1,j+2));
			}
			if(j-2 >= 0) {
				m1[p].push_back(make_pair(i+1,j-2));
			}
		}

		if(i-1 >= 0) {
			if(j+2 < m) {
				m1[p].push_back(make_pair(i-1,j+2));
			}
			if(j-2 >= 0) {
				m1[p].push_back(make_pair(i-1,j-2));
			}
		}
		return;
	}

	int bfs(int s1, int s2, int d1, int d2, int n, int m) {

		pair <int, int> src = make_pair(s1,s2);
		pair <int, int> dest = make_pair(d1,d2);

		unordered_map <pair <int,int> , bool > visited;
		unordered_map <pair <int,int> , int > distance;
		queue <pair <int,int> > q;

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				visited[make_pair(i,j)] = false;
				distance[make_pair(i,j)] = INT_MAX;
			}
		}

		q.push(src);
		visited[src] = true;
		distance[src] = 0;

		while(!q.empty()) {

			pair <int, int> p = q.front();
			q.pop();

			for(auto child : m1[p]) {
				if(!visited[child]) {
					visited[child] = true;
					distance[child] = distance[p]  +1; 
					q.push(child);
				}
			}
		}
		int ans = distance[dest];

		if(ans == INT_MAX) {
			ans = -1;
		}
		return ans;
	}
};


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n ,m, s1,s2,d1,d2;

	cin>>n>>m;

	graph g;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			g.addEdge(i,j,n,m);
		}
	}

	cin>>s1>>s2>>>d1>>d2;

	s1--;  s2--;     // bcoz of 1 based indexing
	d1--;  d2--;

	cout<<g.bfs(s1,s2,d1,d2,n,m)<<endl;



	return 0;
}










