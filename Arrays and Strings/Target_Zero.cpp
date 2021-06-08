#include<bits/stdc++.h>
using namespace std;

vector <int> targetZero(int n) {
	vector <int> v;
	int n1 = n/2;
	for(int i=1;i<=n1;i++) {
		v.push_back(i);
		v.push_back(-1*i);
	}
	if(n%2 == 1) {
		v.push_back(0);
	}
	return v;
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	vector <int> v;
	v = targetZero(n);

	for(int x : v) {
		cout<<x<<" ";
	}



	return 0;
}