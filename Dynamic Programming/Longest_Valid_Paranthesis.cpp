#include<bits/stdc++.h>
using namespace std;

int longestValidParanthesis(string s) {
	stack <int> st;
	int ans =0 , curr = 0;
	int i =0;

	while(i < s.length()) {

		if(s[i] == '(') {
			st.push(curr);
			curr = 0;
		}
		else {
			if(st.empty()) {
				curr = 0;
			}
			else {
				curr = curr + st.top()  +2;
				st.pop();
				ans = max(ans, curr);
			}
		}
		i++;
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

	cout<<longestValidParanthesis(s)<<endl;

	return 0;
}