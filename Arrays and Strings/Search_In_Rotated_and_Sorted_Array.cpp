#include<bits/stdc++.h>
using namespace std;

int SearchInRotatedSortedArray(vector <int> &nums, int target) {
	int n = nums.size();
	int s = 0, e = n-1;

	while(s <= e) {

		int mid = (s+e)/2;

		if(target == nums[mid]) {
			return mid;
		}

		else if(nums[mid] > nums[n-1]) {
			if(target < nums[0] or target > nums[mid]) {
				s = mid+1;
			}
			else {
				e = mid-1;
			}
		}
		else {
			if(target > nums[n-1] or target < nums[mid]) {
				e = mid-1;
			}
			else {
				s = mid+1;
			}
		}
	}
	return -1;

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

	int target;
	cin>>target;

	cout<<SearchInRotatedSortedArray(nums, target)<<endl;

	return 0;
}