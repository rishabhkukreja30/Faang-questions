#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {

	int n = s.length();

	if(n ==0 or k ==0) {
		return 0;
	}

	int l = 0;
	int max_len = 0;
	unordered_map<char, int> m;

	for(int i=0;i<n;i++) {
		char ch = s[i];
		m[ch] = i;

		if(m.size() == k+1) {

			char ch_min_idx = '\0';
			int min_idx = INT_MAX;

			for(auto x : m) {

				if(x.second < min_idx) {
					ch_min_idx = x.first;
					min_idx = x.second;
				}
			}
			l = min_idx + 1;
			m.erase(ch_min_idx);
		}
		max_len = max(max_len, i-l+1);
	}
	return max_len;
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin>>s;

	int k; 
	cin>>k;

	cout<<longestSubstring(s, k)<<endl;

	return 0;
}











