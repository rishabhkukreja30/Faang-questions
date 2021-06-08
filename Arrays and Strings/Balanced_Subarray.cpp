#include<bits/stdc++.h>
using namespace std;

int balancedSubarrayLength(int a[], int n) {
	int i = -1;
	int count = 0 , ans = 0;
	unordered_map <int , int > m;
	m.insert({0,i});

	for(int j=0;j<n;j++) {
		if(a[j] == 0) {
			count--;
		}
		else {
			count++;
		}
		if(m.find(count) != m.end()) {
			ans = max(ans, j-m[count]);
		}
		else {
			m.insert({count, j});
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
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<balancedSubarrayLength(a, n)<<endl;



	return 0;
}