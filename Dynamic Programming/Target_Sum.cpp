#include<bits/stdc++.h>
using namespace std;

int s1(vector <int> &nums) {

	int ans = 0;
	for(int i=0;i<nums.size();i++) {
		ans = ans - nums[i];
	}
	return ans;
}


int s2(vector <int> &nums) {

	int ans = 0;
	for(int i=0;i<nums.size();i++) {
		ans = ans + nums[i];
	}
	return ans;
}

int targetSum(vector <int> &nums, int s) {

	int min_sum = s1(nums);
	int max_sum = s2(nums);

	if(s > max_sum || s < min_sum) {
		return 0;
	}

	int r = nums.size();
	int c = max_sum - min_sum + 1;

	int **dp = new int*[r];
	for(int i=0;i<r;i++) {
		dp[i] = new int[c];
	}

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			dp[i][j] = 0;
		}
	}

	// initiaize 1st row
	for(int i=0;i<c;i++) {
		
		bool op1 = (i+min_sum) == nums[0];
		bool op2 = (i+min_sum) == (-1) * nums[0];

		if(op1) {
			dp[0][i] += 1;
		}

		if(op2) {
			dp[0][i] += 1;
		}
	}

	for(int i=1;i<r;i++) {
		for(int j=0;j<c;j++) {
			int a1 =  (j-nums[i] >= 0) ? dp[i-1][j-nums[i]] : 0;
			int a2 =  (j + nums[i] <c) ? dp[i-1][j+nums[i]] : 0;

			dp[i][j] = a1 + a2;
		}
	}

	return dp[r-1][s-min_sum];
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

	int s;
	cin>>s;

	cout<<targetSum(nums, s)<<endl;



	return 0;
}