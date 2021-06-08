#include<bits/stdc++.h>
using namespace std;

vector <int>  diagonalTraversal(int a[][100], int m, int n) {
	int row = 0, col = 0, dir = 1;
	vector <int> ans;

	for(int i=0;i<m*n;i++) {
		ans[i] = a[row][col];

		if(dir == 1) {
			if(col == n-1) {
				row++;
				dir = -1;
			}
			else if(row == 0) {
				col++;
				dir = -1;
			}
			else {
				row--;
				col++;
			}
		}
		else {
			if(row == m-1) {
				col++;
				dir = 1;
			}
			else if(col == 0) {
				row++;
				dir = 1;
			}
			else {
				row++;
				col--;
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

	int m, n;
	cin>>m>>n;
	int a[100][100];
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}

	vector <int> ans = diagonalTraversal(a, m , n);
	
	for(int x : ans){
		cout<<x<<" ";
	}



	return 0;
}