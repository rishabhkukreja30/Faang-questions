#include<bits/stdc++.h>
using namespace std;

int max_loot(int a[], int n) {

	if(n== 0) {
		return 0;
	}
	if(n== 1){
		return a[0];
	}
	if(n ==2) {
		return max(a[0],a[1]);
	}

	int dp[n];
	dp[0] = a[0];

	dp[1] = max(a[0], a[1]);

	for(int i=2;i<n;i++) {
		dp[i] = max(dp[i-2]  +a[i] , dp[i-1]);
	}
	return dp[n-1];
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}


	cout<<max_loot(a, n)<<endl;

	return 0;
}















