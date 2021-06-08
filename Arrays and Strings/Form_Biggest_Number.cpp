#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	
	string s1 = to_string(a);
	string s2 = to_string(b);

	return (s1 + s2) > (s2 + s1);
}

string largestNumber(vector <int> &nums) {

	sort(nums.begin(), nums.end(), compare);

	int flag = 0;

	for(int i=0;i<nums.size();i++) {    // to check if all elements are zero
		if(nums[i] != 0) {
			flag = 1;
			break;
		}
	}

	if(flag) {
		string s = "";

		for(int i=0;i<nums.size();i++) {
			s += to_string(nums[i]);
		}
	}
	else {
		return "0";
	}
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif



	return 0;
}






