#include <bits/stdc++.h>
using namespace std;

bool containsDuplicates(vector <int> &nums, int k) {
	unordered_map <int, list <int>  >m;

	for(int i=0;i<nums.size();i++) {

		if(m.find(nums[i]) != m.end()) {
			for(auto node: m[nums[i]]) {
				if(abs(i-node) <= k) {
					return true;
				}
			}
		}
		m[nums[i]].push_back(i);
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
	int k;
	cin>>k;

	cout<<containsDuplicates(nums, k)<<endl;

	return 0;
}







