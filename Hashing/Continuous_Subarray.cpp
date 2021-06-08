#include<bits/stdc++.h>
using namespace std;

bool continuousSubarray(vector <int> &nums, int k) {
	unordered_map <int, int> m;
	
	int sum = 0;
	int mod = 0;
	m[0] = -1;

	for(int i=0;i<nums.size();i++) {

		if(k != 0) {
			sum += nums[i];
			mod = sum % k;

			if(m.find(mod) == m.end()) {
				m[mod] = i;
			}
			else if(i - m[mod] > 1) {
				return true;
			}
		}
		if(k == 0 and nums[i] == 0 and i < nums.size() -1 and nums[i+1] == 0) {
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
	
	int k;
	cin>>k;

	cout<<continuousSubarray(nums,k)<<endl;

	return 0;
}