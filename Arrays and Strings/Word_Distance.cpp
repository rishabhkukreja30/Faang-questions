#include<bits/stdc++.h>
using namespace std;

int WordDistance(string a[], int n, string word1, string word2) {
	int w1  = INT_MAX;
	int w2 = INT_MAX;
	int ans = 0;
	for(int i=0;i<n;i++) {
		if(s[i] == word1) {
			w1 = i;
		}
		else if(s[i] == word2) {
			w2 = í;
		}
		ans = min(ans, w1-w2);
	}
	return ans;
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	


	return 0;
}