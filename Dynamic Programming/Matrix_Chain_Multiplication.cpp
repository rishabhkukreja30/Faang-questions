#include<bits/stdc++.h>
using namespace std;

int dp[100][100];

int matrixChain(int m[], int i, int j) {

	//base case
	if(i == j) {
		dp[i][j] = 0;
		return 0;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	int ans = INT_MAX;

	for(int k=i;k<j;k++) {
		int temp = matrixChain(m,i,k) + matrixChain(m, k+1, j) + m[i-1]*m[k]*m[j];
		ans = min(ans, temp);
	}

	dp[i][j] = ans;
	return ans;
}

int matrixChainBottomUp(int m[], int n) {
	int dp[100][100];

	// make diagonal elements 0
	for(int i=1;i<n;i++) {
		dp[i][i] = 0;
	}

	for(int L=2;L<n;L++) {

		for(int i=1;i<=n-L;i++) {
			
			int j = i + L -1;

			dp[i][j] = INT_MAX;

			for(int k=i;k<j;k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + m[i-1]*m[k]*m[j]);
			}

		}
	}
	return dp[1][n-1];
}


int main() {

	
	// #ifndef ONLINE_JUDGEs
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int matrices[] = {1,2,3,4};
	int n = sizeof(matrices)/sizeof(int);

	memset(dp, -1, sizeof dp);

	cout<<matrixChain(matrices, 1, n-1)<<endl;

	for(int i=1;i<n;i++) {
		for(int j=1;j<n;j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<matrixChainBottomUp(matrices, n)<<endl;

	return 0;
}

























