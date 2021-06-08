#include<bits/stdc++.h>
using namespace std;

int Solve(int a[], int n) {

	int left[n] , right[n];

	left[0] = 1;

	for(int i=1;i<n;i++) {
		int ans = 1;
		for(int j=0;j<i;j++) {
			if(a[i] > a[j]) {
				ans = max(ans, left[j] + 1);
			}
		}
		left[i] = ans;
	}

	right[n-1] = 1;

	for(int i=n-2;i>=0;i--) {
		int ans = 1;
		for(int j=i+1;i<n;j++) {
			if(a[i] > a[j]) {
				ans = max(ans, right[j] + 1);
			}
		}
		right[i] = ans;
	}

	int len = 0;
	for(int i=0;i<n;i++) {
		len = max(len, left[i] + right[i] - 1);
	}
	return len;
	cout<<len;
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


	cout<<Solve(a, n)<<endl;



	return 0;
}










