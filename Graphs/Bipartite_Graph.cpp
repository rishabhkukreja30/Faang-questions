#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector <vector <int>> &graph) {
	int vertices = graph.size();

	vector <string> color(vertices,"white");

	//bfs
	for(int i=0;i<vertices;i++) {

		if(color[i] == "white") {
			queue <int> q;
			q.push(i);
			color[i] = "blue";

			while(!q.empty()) {
				int f = q.front();
				q.pop();

				for(int child : graph[f]) {
					if(color[child] == "white") {
						if(color[f] == "red") {
							color[child] = "blue";
						}
						else {
							color[child] = "red";
						}
					}
					else {
						if(color[f] == color[child]) {
							return  false;
						}
					}
				}
			}
		}
	}
	return true;
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int vertices;
	cin>>vertices;

	vector <vector <int>> graph;

	for(int i=0;i<vertices;i++) {
		int edges;
		cin>>edges;
		vector <int> temp(edges,0);
		for(int j=0;j<edges;j++) {
			cin>>temp[j];
		}
		graph.push_back(temp);
	}

	if(isBipartite) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}



	return  0;
}
