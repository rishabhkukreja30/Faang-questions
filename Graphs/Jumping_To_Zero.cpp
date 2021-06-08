#include<bits/stdc++.h>
using namespace std;

bool canReach(vector <int> &arr, int start) {

	// vector of zeroes
	vector <int> zeroes;

	for(int i=0;i<arr.size();i++) {
		if(arr[i] == 0) {
			zeroes.push_back(i);
		}
	}

	// build a map
	unordered_map <int, list <int>> m;

	for(int i=0;i<arr.size();i++) {
		if(arr[i] == 0) {
			continue;
		}

		if(i + arr[i] < arr.size()) {
			m[i].push_back(i+arr[i]);
		}
		if(i - arr[i] >= 0) {
			m[i].push_back(i - arr[i]);
		}
	}

	// bfs
	unordered_map <int, bool> visited;

	for(int i=0;i<arr.size();i++) {
		visited[i] = false;
	}

	queue <int> q;
	q.push(start);
	visited[start] = true;

	while(!q.empty()) {
		int f = q.front();
		q.pop();

		for(int child : m[f]) {
			if(!visited[child]) {
				q.push(child);
				visited[child] = true;
			}
		}
	}

	for(int i=0;i<zeroes.size();i++) {
		if(visited[zeroes[i]] == true) {
			return true;
		}
	}
	return false;
}

// or
     bool canReach(vector<int>& arr, int start) {
            queue<int>q;
            int n=arr.size();
            bool visited[n];
            for(int i=0;i<n;i++) {
                visited[i] = false;
            }
            q.push(start);
            visited[start] = true;
            while(!q.empty()){
                int x= q.front();
                q.pop();
                if(arr[x]==0)
                    return true;
                if(arr[x]+x<n && arr[x]+x>=0 && visited[arr[x]+x]==false){
                    visited[arr[x]+x]=true;
                    q.push(arr[x]+x);
                }
                if(x-arr[x]<n && x-arr[x]>=0 && visited[x-arr[x]]==false){
                    visited[x-arr[x]]=true;
                    q.push(x-arr[x]);
                }

            }
            return false;
        }























