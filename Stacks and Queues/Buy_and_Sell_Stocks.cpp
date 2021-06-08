#include<bits/stdc++.h>
using namespace std;

int maxProfit(int a[], int n) {
	stack <int> s;
	s.push(a[0]);
	int max_profit = 0;

	for(int i=1;i<n;i++) {

		if(!s.empty() and a[i] < s.top()) {
			s.push(a[i]);
		}
		else {
			int profit = a[i] - s.top();
			max_profit = max(profit, max_profit);
		}
	}
	return max_profit;
}

// or
int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int min_price = INT_MAX;
        
    for(int i=0;i<prices.size();i++) {
        min_price = min(min_price, prices[i]);
        max_profit = max(max_profit, prices[i]- min_price);
    }
    return max_profit;
}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cout<<maxProfit(a,n)<<endl;

	return 0;
}