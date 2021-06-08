#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(int a[], int n) {
	for(int i=0;i<n;i++) {
		if(a[i] <=0 a[i] >n+1) {
			a[i] = n+2;
		}
	}

	for(int v :a) {
		int i = v> 0 ? v-1 : -v-1;

		if(i>=0 and i<n) {
			a[i] = -abs(a[i]);
		}
	}

	for(int i=0;i<n;i++) {
		if(a[i] > 0) {
			return i+1;
		}
	}
	return n+1;
}


int main() {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	return  0;
}