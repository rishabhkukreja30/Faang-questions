#include<bits/stdc++.h>
using namespace std;


int partyHalls(int s[], int e[], int n) {
	sort(s,s+n);
	sort(e,e+n);

	int i= 0, j= 0, ans =0, count = 0;
	while(i <n and j < n) {
		if(s[i] < e[j]) {
			count++;
			i++;
		}
		else {
			count--;
			j++;
		}
		ans = max(ans, count);
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
	int s[n];
	int e[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		cin>>e[i];
	}

	cout<<partyHalls(s,e, n)<<endl;

	return 0;
}


