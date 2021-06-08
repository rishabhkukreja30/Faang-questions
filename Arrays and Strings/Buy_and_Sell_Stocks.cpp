#include<bits/stdc++.h>
using namespace std;

int maxProfit(int a[], int n) {
	if(n == 0) {
		return 0;
	}

	int ans = 0;
	int peek = a[0];
	int valley = a[0];
	int i = 0;

	while(i < n-1) {
		//valley
		while(i < n-1 and a[i] >= a[i+1]) {
			i++;
		}
		valley = a[i];
		//peek
		while(i < n-1 and a[i] <= a[i+1]) {
			i++;
		}
		peek = a[i];

		ans += peek - valley;
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

	cout<<maxProfit(a, n)<<endl;


	return 0;
}