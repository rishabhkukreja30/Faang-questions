#include<bits/stdc++.h>
using namespace std;

bool overlappingRectangles(vector <int> &rect1 , vector <int> &rect2) {
	if(rect1[2] <= rect2[0] || rect[1] >= rect2[3] || rect1[0]  >= rect2[2] || rect1[3] <= rect2[1]) {
		return false;
	}
	return true;
}


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;



	return 0;
}