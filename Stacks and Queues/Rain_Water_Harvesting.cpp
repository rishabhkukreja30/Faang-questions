#include<bits/stdc++.h>
using namespace std;

int trap_water(int a[], int n) {

	 //corner case
	if(n == 0) {
		return 0;
	}
	int l[n] , r[n];

	l[0] = a[0];
    r[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        l[i] = max(l[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i + 1], a[i]);
    }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += (min(l[i], r[i]) - a[i]);
    }
    return water;
}


// O(1) space - best approach
int trap_water_optimised(int height[], int n) {     // 2 pointer
	int left = 0 , right = n-1;
	int res = 0;
	int left_max = 0, right_max = 0;

	while(left <= right) {

		if(height[left] <=  height[right]) {

			if(height[left] >= left_max ) {
				left_max = height[left];
			}
			else {
				res += left_max - height[left];
			}
			left++;
		}
		else {

			if(height[right] >= right_max) {
				right_max = height[right];
			}
			else {
				res += right_max - height[right];
			}
			right--;
		}
	}
	return res;
}


int main() {


	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++) {
		cin>>a[i];
	}

	cout<<trap_water(a,n)<<endl;

	return 0;
}






