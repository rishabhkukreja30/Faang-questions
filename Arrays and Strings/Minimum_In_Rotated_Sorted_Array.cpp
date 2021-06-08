#include<bits/stdc++.h>
using namespace std;

int minimumInRotatedSortedArray(vector <int> &nums) {
	int n = nums.size();
	int s = 0, e = n-1;

	if(nums[0] < nums[n-1]) {
		return nums[0];
	}

	while(s <= e) {
		 int mid = (s+e)/2;

		 if(mid-1 >=0 and nums[mid] < nums[mid-1]) {
		 	return nums[mid];
		 }
		 else if(nums[mid] > nums[n-1]) {
		 	s = mid +1;
		 }
		 else {
		 	e = mid -1;
		 }
	}
	return nums[0];
}


int main() {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	vector <int> nums;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}

	cout<<minimumInRotatedSortedArray(nums)<<endl;

	return 0;
}