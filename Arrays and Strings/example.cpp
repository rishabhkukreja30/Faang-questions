#include<bits/stdc++.h>
using namespace std;





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

	for(int i=0;i<n;i++) {
		cout<<a[i]<<" ";
	}


	return 0;
}