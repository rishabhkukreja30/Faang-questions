#include<bits/stdc++.h>
using namespace std;

int closestSum(vector <int> &nums, int target) {

	sort(nums.begin(),nums.end());

	int closestDiff = INT_MAX;
	int closeSum;

	for(int i=0;i<nums.size()-3;i++) {

		int sum = 0;
		int j = i+1 , k = nums.size()-1;
		sum += nums[i] + nums[j] + nums[k];

		while(j<k) {

			if(abs(sum - target) < closestDiff)  {
				closestDiff = abs(sum-target);
				closeSum = sum;
			}
			if(sum < target) {
				sum -= nums[j];
				j++;
				sum += nums[j];
			}
			else if(sum > target) {
				sum -= nums[k];
				k--;
				sum += nums[k];
			}
			else {
				return sum;
			}
		}
	}
	return closeSum;
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

	cout<<closestSum(nums, target)<<endl;



	return 0;
}