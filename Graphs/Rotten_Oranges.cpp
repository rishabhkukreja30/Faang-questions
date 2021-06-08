#include<bits/stdc++.h>
using namespace std;

typedef pair <pair <int, int>, int > node;   // row, column, depth

int rottenOranges(int arr[][], int r, int c) {

	queue <node> q;

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			
			if(arr[i][j] == 2) {
				q.push({{i,j},0});
			}
		}
	}

	int ans = 0;
	int row_index[] = {0,0,-1,1};
	int col_index[] = {1,-1,0,0};

	// bfs
	while(!q.empty()) {
		node f = q.front();
		q.pop();

		int row = f.first.first;
		int col = f.first.second;
		int depth = f.second;

		//iterate in all four directions
		for(int i=0;i<4;i++) {
			int new_row = row + row_index[i];
			int new_col = col + col_index[i];

			if(new_row >=0 && new_row<r && new_col >=0 && new_col < c && arr[new_row][new_col] == 1) {
				arr[new_row][new_col] = 2;    // rot the adjacent orange
				q.push({{new_row,new_col},depth+1});
			}
		}
		ans = max(ans, depth);
	}
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(arr[i][j] == 1) {
				return -1;
			}
		}
	}

	return ans;
}



int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif



	return 0;
}