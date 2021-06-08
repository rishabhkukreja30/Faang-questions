#include<bits/stdc++.h>
using namespace std;


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> graph;
        int indegree[numCourses];
        for(int i=0;i<numCourses;i++) {
            indegree[i] = 0;
        }
        int n = prerequisites.size();
        for(int i=0;i<n;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> zero_indegree;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                zero_indegree.push(i);
            }
        }
        
        int edges_removed = 0;
        while(!zero_indegree.empty()){
            int course = zero_indegree.front();
            edges_removed++;
            zero_indegree.pop();
            
            for(auto child:graph[course]){
               
                indegree[child]--;
                if(indegree[child] == 0){
                    zero_indegree.push(child);
                }
            }
        }
        if(edges_removed == numCourses){
            return true;
        }
        else return false;
    }



int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int numCourses;
	cin>>numCourses;

	int edges;
	cin>>edges;

	vector <vector <int > >dependencies;
	for(int i=0;i<edges;i++) {
		int a, b;
		cin>>a>>b;
		dependencies.push_back({a,b});
	}

	cout<<canFinish(numCourses, dependencies)<<endl;

	return 0;
}











