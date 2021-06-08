#include<bits/stdc++.h>
using namespace std;

vector <int> productOfArrayExceptSelf(int a[], int n) {
	vector <int> left;
	vector <int> right;

	left[0] = 1;
	for(int i=1;i<n;i++) {
		left[i] = left[i-1] * a[i-1];
	}

	right[n-1] = 1;
	for(int i=n-2;i>=0;i--) {
		right[i] = right[i+1] * a[i+1];
	}

	vector <int> ans;
	for(int i=0;i<n;i++) {
		ans[i] = left[i] * right[i];
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
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	vector <int> res = productOfArrayExceptSelf(a, n);

	for(int x : res) {
		cout<<x<<" ";
	}


	return 0;
}