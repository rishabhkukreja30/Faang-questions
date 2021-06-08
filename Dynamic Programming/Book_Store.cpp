#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int Solve(int a[], int left, int right) {
	//base case
	if(right - left <= 1) {
		return 0;
	}

	if(dp[left][right] != -1) {
		return dp[left][right];
	}

	int ans = 0;
	for(int pivot = left+1;pivot<right;pivot++) {
		ans  = max(ans, a[left]*a[pivot]*a[right] + Solve(a,left, pivot) + Solve(a,pivot,right));
	}

	return dp[left][right] = ans;
}



int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	memset(dp, -1, sizeof dp);

	int a[n+2];
	a[0] = a[n+1] = 1;

	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}

	cout<<Solve(a,0, n+1)<<endl;

	return 0;
}









