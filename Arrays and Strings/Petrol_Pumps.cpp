#include<bits/stdc++.h>
using namespace std;

int petrolPumps(int petrol[] , int cost[], int n) {
	int net = 0 , cur = 0, start = 0;

	for(int i=0;i<n;i++) {
		net += petrol[i] - cost[i];
		cur += petrol[i] - cost[i];

		if(cur < 0) {
			cur = 0;
			start = i+1;
		}
	}
	if(net < 0 ) {
		return -1;
	}
	return start;
}

int main() {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int petrol[n] , cost[n];
	
	for(int i=0;i<n;i++) {
		cin>>petrol[i];
	}

	for(int i=0;i<n;i++) {
		cin>>cost[i];
	}

	cout<<petrolPumps(petrol, cost, n)<<endl;

	return 0;
}



