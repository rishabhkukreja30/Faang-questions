#include<bits/stdc++.h>
using namespace std;

int longestAP(vector <int> &nums) {
	int n = nums.size();
	if(n == 1) {
		return 1;
	}

	unordered_map <int, list <int> > m;
	int res = 2;

	for(int i=0;i<n;i++) {
		m[nums[i]].push_back(i);
	}

	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {

			int d = nums[j] - nums[i];
			int num = nums[j] + d;
			int count = 2;
			int pos = j;

			while(m.find(num) != m.end()) {
				bool flag = false;   // to handle the case if num value is not found at index greater than pos
				for(auto index: m[num] ) {
					if(index > pos) {
						count++;
						pos = index;
						num += d;
						flag = true;
						break;
					}
				}
				if(!flag) {
					break;
				}
			}
			res = max(res, count);
		}
	}
	return res;
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

	cout<<longestAP(nums)<<endl;

	return 0;
}