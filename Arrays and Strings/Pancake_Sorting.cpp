#include<bits/stdc++.h>
using namespace std;

int find(vector <int> &a, int n) {
	for(int i=0;i<n;i++) {
		if(a[i] == n) {
			return i;
		}
	}
	return -1;
}

vector <int> pancakeSort(vector <int> &a, int n) {
	vector <int> ans;
	int idx = find(a,n);

	while(n > 0 ) {
		if(idx != n-1) {
			reverse(a.begin() , a.begin() + idx+1);
			reverse(a.begin(),a.end());
			ans.push_back(idx+1);
			ans.push_back(n);
		}
		n--;	
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
	vector <int> a;
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	vector <int> ans = pancakeSort(a, n);

	for(int i=0;i<ans.size();i++) {
		cout<<ans[i];
	}


	return 0;
}

