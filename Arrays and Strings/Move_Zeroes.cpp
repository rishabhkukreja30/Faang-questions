#include<bits/stdc++.h>
using namespace std;

void moveZeroes(int a[], int n) {
	
	int j = 0;
	for(int i=0;i<n;i++) {
		if(a[i] != 0) {
			swap(a[i], a[j]);
			j++;
		}
	}
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

	moveZeroes(a,n);

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}


	return 0;
}