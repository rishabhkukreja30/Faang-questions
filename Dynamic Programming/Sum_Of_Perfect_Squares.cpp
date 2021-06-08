#include<bits/stdc++.h>
using namespace std;

int sumOfPerfectSquares(int n, int dp[]) {

	if(n== 0) {
		dp[n] = 0;
		return 0;
	}
	if(n < 0) {
		return INT_MAX;
	}

	if(dp[n] != -1) {
		return dp[n];
	}

	int ans = INT_MAX;

	for(int i=1;i*i<=n;i++) {
		ans = min(ans, sumOfPerfectSquares(n-i*i, dp));  
	}

	return dp[n] = ans + 1;
}

int bottomup(int n){

	int dp[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = -1;
	}

	dp[0] = 0;

	for(int i=1;i<=n;i++) {
		int ans = INT_MAX;

		for(int j=1;j*j<=i;j++) {
			int subans  = dp[i-j*j];
			ans = min(ans, subans);
		}
		dp[i] = 1 + ans;
	}
	return dp[n];
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int dp[n+1];
	for(int i=0;i<=n;i++) {
		dp[i] = -1;
	}



	cout<<sumOfPerfectSquares(n, dp)<<endl;
	cout<<bottomup(n)<<endl;

	return 0;
}










