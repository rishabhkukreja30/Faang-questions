#include<bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector <int> &nums, int k) {

	unordered_map <int, int> m;
	int pre = 0;
	m[pre] = 1;
	int ans = 0;

	for(int i=0;i<nums.size();i++) {

		pre += nums[i];
		if(m.find(pre - k) != m.end()) {
			ans += m[pre -k];
		}
		
		if(m.find(pre) != m.end()) {
			m[pre]++;
		}
		else {
			m[pre] = 1;
		} 
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
	vector <int> nums;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}

	int k;
	cin>>k;

	cout<<numberOfSubarrays(nums, k)<<endl;

	return 0;
}