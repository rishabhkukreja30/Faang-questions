#include<bits/stdc++.h>
using namespace std;

vector <int>  kClosestElements(int a[], int n, int k, int x) {
	int curr_sum =  0, pos = 0;
	
	for(int i=0;i<k;i++) {
		curr_sum += abs(x - a[i]);
	}

	int sum = curr_sum;
	for(int i=1;i<n-k;i++) {
		curr_sum += abs(x - a[i-1]);
		curr_sum += abs(x - a[i-k+1]);

		if(curr_sum < sum) {
			curr_sum = sum;
			pos = i;
		}
	}

	vector <int > ans;
	for(int i=0;i<k;i++) {
		ans.push_back(a[i+pos]);
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
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	int x, k;

	cin>>x>>k;

	vector <int> ans = kClosestElements(a,n,k ,x);

	for(int x : ans) {
		cout<<x<<" ";
	}

	return 0;
}


