#include<bits/stdc++.h>
using namespace std;

int maxSquareOfOnes(vector <vector <int> > &matrix)  {

	if(matrix.size() == 0) {
		return 0;
	}

	int rows = matrix.size() , cols = matrix[0].size();

	int max_ans = 0;
	int **dp = new int*[rows];
	for(int i=0;i<rows;i++) {
		dp[i] = new int[cols];
	}

	//initialize last row
	for(int j=0;j<cols;j++) {
		dp[rows-1][j] = matrix[rows-1][j];
		max_ans = max(max_ans, dp[rows-1][j]);
	}
	//initialize last column
	for(int i=0;i<rows;i++) {
		dp[i][cols-1] = matrix[i][cols-1];
		max_ans = max(max_ans, dp[i][cols-1]);
	}

	// start from bottom right in 2nd last row
	for(int i=rows-2;i>=0;i--) {
		for(int j=cols-2;j>=0;j--) {

			int step1 = dp[i][j+1];
			int step2 = dp[i+1][j];
			int step3 = dp[i+1][j+1];

			int ans = min(step1, min(step2, step3));

			if(matrix[i][j] == 0) {
				dp[i][j] = 0;
			}
			else {
				ans++;
				max_ans = max(max_ans, ans);
				dp[i][j] = ans;
			}
		}
	}
	return max_ans * max_ans; 
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int rows, cols;
	cin>>rows,cols;

	vector <vector <int> > matrix;

	for(int i=0;i<rows;i++) {
		vector <int> temp(cols);
		for(int j=0;j<cols;j++) {
			cin>>temp[j];
		}
		matrix.push_back(temp);
	}

	cout<<maxSquareOfOnes(matrix)<<endl;

	return 0;
}