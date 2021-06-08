#include<bits/stdc++.h>
using namespace std;

void unique_strings(char a[]) {

	int last_index[26] = {0};
	bool presentInStack[26] = {0};

	for(int i=0;a[i] != '\0';i++) {
		last_index[a[i]-'a'] = i; 
	}

	stack <char> s;

	for(int i=0;a[i]!='\0';i++) {
		char ch = a[i];

		if(!presentInStack[ch-'a']) {

			while(!s.empty() and ch<s.top() and last_index[s.top()-'a']>i) {
				presentInStack[s.top()-'a'] = false;
				s.pop();
			}

			s.push(ch);
			presentInStack[ch-'a'] = true;
		}
	}

	vector <char> ans;
	while(!s.empty()) {
		char ch = s.top();
		ans.push_back(ch);
		s.pop();
	}

	reverse(ans.begin(), ans.end());
	for(auto x : ans) {
		cout<<x;
	}

}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char a[1000000];
	cin>>a;

	unique_strings(a);

	return 0;
}
