#include<bits/stdc++.h>
using namespace std;

int maximumProductSubarray(int a[], int n) {
	
	if(n == 1) {
		return a[0];
	}


	int pp =1, np = 1, ans = INT_MIN;

	bool hasZero = false, hasPos = false;

	for(int i=0;i<n;i++) {
		
		if(a[i] > 0) {
			hasPos = true;
			pp *= a[i];

			if(np != 1) {
				np *= a[i];
			}
		}

		else if(a[i] < 0) {
			int temp = pp;
			pp = max(1, np*a[i]);
			np = temp * a[i];
		}
		else {
			np = pp = 1;
			hasZero = true;
		}
		ans = max(ans, pp);
	}
	if(ans == 1) {
		if(hasPos) {
			return  ans;
		}
		if(hasZero) {
			return 0 ;
		}
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

	cout<<maximumProductSubarray(a, n)<<endl;


	return 0;
}