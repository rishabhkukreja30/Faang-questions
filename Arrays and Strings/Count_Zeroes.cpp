#include<bits/stdc++.h>
using namespace std;


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int count_zeroes = 0;
	while(n > 0) {
		n /= 5;
		count_zeroes++;
	}

	cout<<count_zeroes<<endl;


	return 0;
}