#include<bits/stdc++.h>
using namespace std;

string decodeString(string s) {
	string ans = "" , temp = "";
	stack <pair <string, int> > st;
	int i=0;

	while(i<s.length()) {

		if(isdigit(s[i])) {
			int num = 0;
			while(isdigit(s[i])) {
				int temp_num = s[i]- '0';
				num = num*10 + temp_num;
				i++;
			}
			st.push(make_pair(temp, num));
			temp = "";
		}
		else if(isalpha(s[i])) {
			temp += s[i];
		}
		else if(s[i] == ']') {
			pair <string, int> p = st.top();
			st.pop();
			string curr = p.first;
			for(int i=0;i<p.second;i++) {
				curr += temp;
			}
			if(s.empty()) {
				ans += curr;
				temp = "";
			}
			else {
				temp = curr;
			}
		}
		i++;
	}
	ans += temp;
	return ans;
}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s;
	cin>>s;

	string ans = decodeString(s);
	cout<<ans;

	return 0;
}