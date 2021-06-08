#include<bits/stdc++.h>
using namespace std;

vector <int> majorityElements(vector <int > v) {
	
	int element1 = v[0];
	int count1 = 1;

	int element2 = 0;
	int count2 = 0;

	for(int i=1;i<v.size();i++) {
		if(v[i] == element1) {
			count1++;
		}
		else if(v[i] == element2) {
			count2++;
		}
		else if(count1 == 0) {
			element1 = v[i];
			count1 = 1;
		}
		else if(count2 == 0) {
			element2 = v[i];
			count2 = 1;
		}
		else {
			count1--;
			count2--;
		}
	}

	//iterate and find out if count of element1 and element2 is more than n/3 or not
	count1 = count2 = 0;
	for(int i=0;i<v.size();i++) {
		if(v[i] == element1) {
			count1++;
		}
		else if(v[i] == element2) {
			count2++;
		}
	}
	vector <int> ans;
	if(count1 > v.size()/3) {
		ans.push_back(element1);
	}
	if(count2 > v.size()/3) {
		ans.push_back(element2);
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

	vector <int> v;
	int x;
	for(int i=0;i<n;i++) {
		cin>>x;
		v.push_back(x);
	}

	vector <int> ans;
	ans = majorityElements(v);

	if(ans.size() == 0) {
		cout<<"No majority elements"<<endl;
	}
	else {
		for(int i=0;i<ans.size();i++) {
			cout<<ans[i]<<" ";
		}
	}

	return 0;
}

