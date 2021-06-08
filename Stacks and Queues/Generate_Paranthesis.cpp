#include<bits/stdc++.h>
using namespace std;

void generateParanthesis(int n, string ans, int open, int close) {

	if(close == n) {
		cout<<ans<<endl;
		return;
	}
	if(open < n) {
		generateParanthesis(n,ans+'(',open+1,close);
	}
	if(close < open) {
		generateParanthesis(n,ans+')',open, close+1);
	}
}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	string ans = "";

	generateParanthesis(n,ans, 0, 0);

	return 0;
}