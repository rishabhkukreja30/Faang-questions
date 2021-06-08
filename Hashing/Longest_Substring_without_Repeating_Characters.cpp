#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s) {

	unordered_map <char, int> m;
	
	int j=0;
	int ans = 0;

	for(int i=0;i<s.length();i++) {
		char ch = s[i];

		if(m.find(ch) != m.end()) {
			j = max(m[ch] + 1, j);
		}
		ans = max(ans, i-j+1);
		m[ch] = i;
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

	cout<<longestSubstring(s)<<endl;

	return 0;
}



