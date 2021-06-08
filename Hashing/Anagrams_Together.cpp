#include<bits/stdc++.h>
using namespace std;

vector <vector <string>> groupAnagrams(vector <string> words) {
	unordered_map <string , vector <string> > m;

	for(int i=0;i<words.size();i++) {

		string s = words[i];
		sort(s.begin(), s.end());

		if(m.find(s) != m.end()) {
			m[s].push_back(words[i]);
		}
		else {
			m[s].push_back(words[i]);
		}
	}
	vector <vector <string>> ans;

	for(auto p: m) {
		ans.push_back(p.second);
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
	vector <string> v;

	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		v.push_back(s);
	}

	vector <vector <string> > ans = groupAnagrams(v);

	for(auto s : ans) {
		for(int i=0;i<s.size();i++) {
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}














