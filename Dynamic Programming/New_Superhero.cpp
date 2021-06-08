#include<bits/stdc++.h>
using namespace std;

int pallindromic_substrings(string s) {
	int n = s.length()	;
	bool dp[1001][1001] = {0};

	for(int i=0;i<n;i++) {
		dp[i][i] = true;      // i=j -> diagonal
	}

	for(int i=0;i<n-1;i++) {
		if(s[i] == s[i+1]) {
			dp[i][i+1] = true;
		}
	}

	for(int d=2;d<n;d++) {
		int i=0 , j=d;

		while(j<n) {
			if(s[i] == s[j] && dp[i+1][j-1]) {
				dp[i][j] = true;
			}
			else {
				dp[i][j] = false;
			}
			i++; j++;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(dp[i][j] == true) {
				ans++;
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

	string s;
	cin>>s;

	cout<<pallindromic_substrings(s)<<endl;


	return 0;
}