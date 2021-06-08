#include <bits/stdc++.h>
using namespace std;

bool containsDuplicates(vector <int> &nums) {
	unordered_map <int, bool >m;

	for(int i=0;i<nums.size();i++) {
		if(m.find(nums[i]) == m.end()) {
			m[nums[i]] = true;
		}
		else {
			return true;
		}
	}
	return false;
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

	cout<<containsDuplicates(nums)<<endl;

	return 0;
}