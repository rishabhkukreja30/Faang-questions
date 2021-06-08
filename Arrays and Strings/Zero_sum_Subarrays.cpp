#include<bits/stdc++.h>
using namespace std;

int zeroSumSubarrays(int a[], int n) {
	int prefix[n];
	unordered_map <int, int> m;
	m.insert({0,1});
	prefix[0] = a[0];
	
	if(m.find(prefix[0]) != m.end()) {
		m[prefix[0]]++;
	}
	else {
		m.insert({prefix[0], 1});
	}

	for(int i=1;i<n;i++) {
		prefix[i] = prefix[i-1] + a[i];
		if(m.find(prefix[i]) != m.end()) {
			m[prefix[i]]++;
		}
		else {
			m.insert({prefix[i], 1});
		}
	}

	int count = 0;
	for(auto key : m) {
		int val = key.second;
		if(val > 1) {
			count += val*(val-1)/2;
		}
	}
	return count;

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

	cout<<zeroSumSubarrays(a,n) <<endl;

	return 0;
}