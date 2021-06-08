#include<bits/stdc++.h>
using namespace std;


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int ans =0 , maxh = INT_MIN;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		if(num >= maxh) {
			ans++;
			maxh = num;
		}
	}
	cout<<ans<<endl;

	return 0;
}