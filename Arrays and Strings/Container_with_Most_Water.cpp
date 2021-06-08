#include<bits/stdc++.h>
using namespace std;


int main() {

	
	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;

	int *heights = new int[n+1];
	for(int i=0;i<n;i++) {
		cin>>heights[i];
	}


	int left = 0;
	int right  = n-1;
	int area = 0;
	while(left < right) {
		area = max(area, min(heights[left], heights[right]) * (right - left));
		if(heights[left] < heights[right]) {
			left++;
		}
		else {
			right--;
		}
	}

	cout<<area<<endl;

	return 0;

}