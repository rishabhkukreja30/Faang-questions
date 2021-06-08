#include<bits/stdc++.h>
using namespace std;


vector <int> killProcess(vector <int> &id, vector <int> &parent_id, int kill) {

	unordered_map <int, list<int> > m;
	vector <int> v;

	for(int i=0;i<id.size();i++) {
		m[parent_id[i]].push_back(id[i]);
	}

	queue <int> q;
	q.push(kill);
	v.push_back(kill);

	while(!q.empty()) {
		
		int temp = q.front();
		q.pop();

		for(int child :m[temp]) {

			v.push_back(child);
			q.push(child);
		}
	}
	return v;
}

int main() {

	
	// #ifndef ONLINE_JUDGEs
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif


	return  0;
}