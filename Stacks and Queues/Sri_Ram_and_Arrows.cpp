#include<bits/stdc++.h>
using namespace std;

void Lord_Ram(int a[], int n) {

	stack <int> s;

	for(int i=0;i<n;i++) {

		if(!s.empty() and s.top() >0 and a[i] < 0) {
			// collision will occur
			bool flag = true;  //whether we want to insert or not
			while(!s.empty() and s.top() > 0 and a[i] < 0) {
				if(abs(s.top()) == abs(a[i])) {
					s.pop();
					flag = false;
				}
				else if(abs(a[i]) > abs(s.top())) {
					s.pop();
					flag = true;
				}
				else if(abs(a[i]) < abs(s.top())) {
					flag = false;
					break;
				}
			}
			if(flag) {
				s.push(a[i]);
			}
		}
		else {
			s.push(a[i]);
		}
	}

	vector <int> ans;
	while(!s.empty()) {
		int x = s.top();
		ans.push_back(x);
		s.pop();
	}

	reverse(ans.begin(), ans.end());

	for(int i :ans) {
		cout<<i<<" ";
	}
}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	Lord_Ram(a,n);


	return 0;
}