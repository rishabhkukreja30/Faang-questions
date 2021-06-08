#include<bits/stdc++.h>
using namespace std;

int isSingle(int a[], int m, int n) {
	if(m ==0 and a[0] != a[1]) {
		return true;
	}
	if(m == n-1 and a[m] != a[m-1]) {
		return true;
	}
	if(a[m] != a[m+1] and a[m] != a[m-1]) {
		return true;
	}
	return false;
}

int lonelyElement(int a[], int n) {
	if( n==1 ) {
		return a[0];
	}
	int s = 0;
	int e = n-1;
	while(s<=e) {
		int m = (s+e)/2;
		if(isSingle(a,m, n)) {
			return a[m];
		}
		if((m+1) < n and a[m] == a[m+1]) {
			if(m%2 == 0) {
				s = m+1;
			}
			else {
				e = m-1;
			}
		}

		if(m >= 1 and a[m] == a[m-1]) {
			if(m%2 == 1) {
				s = m+1;
			}
			else {
				e = m-1;
			}
		}
	}
	return a[s];

}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int a[n+1];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cout<<lonelyElement(a,n)<<endl;



	return 0;
}


// or
int single(vector <int> &nums) {
	int n = nums.size();

	int low = 0, high = n-2;

	while(low <= high) {
		int mid = (low+high) >> 1;

		if(nums[mid] == nums[mid^1]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	return nums[low];
}
