#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector <int> &candies) {

	vector <int> v;
	v[0] = 1;

	for(int i=1;i<candies.size();i++) {
		if(candies[i] > candies[i-1]) {
			v[i] = v[i-1] + 1;
		}
		else {
			v[i] = 1;
		}
	}

	for(int i=candies.size()-1;i>=0;i--) {
		if(candies[i] > candies[i+1]) {
			if(v[i] <= v[i+1]) {
				v[i] = v[i+1] + 1;
			}
		}
	}

	int ans = 0;
	for(int i: v) {
		ans += i;
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

	vector <int> candies;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		candies.push_back(num);
	}

	cout<<distributeCandies(candies)<<endl;


	return 0;
}









