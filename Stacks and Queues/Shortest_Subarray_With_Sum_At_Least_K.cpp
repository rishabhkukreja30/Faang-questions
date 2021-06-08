#include<bits/stdc++.h>
using namespace std;

int subArraySum(int a[], int n, int k) {

	int sum[n];
	int x = 0;
	for(int i=0;i<n;i++) {
		x += a[i];
		sum[i] = x;
	}

	deque< pair <int, int> > q;
	q.push_back({0,-1});

	int ans = INT_MAX;
	
	for(int i=0;i<n;i++) {

		while(!q.empty() && sum[i]-q.front().first >= k) {
			//calculate the length
			ans = min(ans, i-q.front().second);
			q.pop_front();
		}

		while(!q.empty() && sum[i] <= q.back().first) {
			q.pop_back();
		}

		q.push_back({sum[i], i});
	}

	if(ans == INT_MAX) {
		return -1;
	}
	else {
		return ans;
	}
}

int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,k;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	cin>>k;

	cout<<subArraySum(a,n,k)<<endl;




	return 0;
}