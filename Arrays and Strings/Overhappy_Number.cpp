#include<bits/stdc++.h>
using namespace std;

int update(int n) {
	int s = 0;
	while(n > 0)  {
		int digit = n%10;
		s += digit*digit;
		n  = n/10;
	}
	return s;
}

bool check(unordered_map < int, bool > m, int n) {
	if(n == 1) {
		return true;
	}
	if(m.find(n) != m.end()) {
		return false;
	}
	m.insert({n, true});
	n = update(n);
	return check(m, n);
}

bool isHappy(int n) {
	unordered_map < int, bool > m;
	return check(m,n);
}

int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	cout<<isHappy(n)<<endl;


	return 0;
}
