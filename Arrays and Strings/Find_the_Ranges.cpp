#include<bits/stdc++.h>
using namespace std;


vector <string> findRnges(vector <int> &nums) {
	int n = nums.size();

	vector <string> ans;

	int i=0;
	while(i< n) {
		string temp = "";
		temp += to_string(nums[i]);
		int num = nums[i];

		while(i+1<n and nums[i+1] == nums[i]  +1) {
			i++;
		}
		if(nums[i] != num) {
			temp += "->";
			temp += to_string(nums[i]);
		}
		ans.push_back(temp);
		i++;
	}
	return ans;
}


int main() {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	return  0;
}