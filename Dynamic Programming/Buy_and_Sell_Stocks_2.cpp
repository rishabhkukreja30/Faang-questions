#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector <int> &prices) {

	int n = prices.size();
	if(n == 0 or n== 1) {
		return 0;
	}

	int left[n] , minl = prices[0];     // minl = min on left before current element
	left[0] = 0;

	for(int i=1;i<n;i++) {
		left[i] = max(left[i-1], prices[i]-minl);
		minl = min(minl, prices[i]);
	}

	int right = 0, maxr = 0;      // maxr = max on right after current element
	int ans = 0;

	for(int i=n-1;i>=0;i--) {
		right = max(right, maxr - prices[i]);
		maxr = max(maxr, prices[i]);
		ans = max(ans, left[i]  +right);
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

	vector <int> prices;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		prices.push_back(num);
	}

	cout<<maxProfit(prices)<<endl;


	return 0;
}