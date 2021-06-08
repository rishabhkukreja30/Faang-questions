#include<bits/stdc++.h>
using namespace std;

int median(int a[], int b[], int m, int n) {
	if(m > n) {
		swap(a,b);
	}

	float median = 0;
	int  l =0;
	int r = m;
	int halflen = (m+n+1)/2;

	while(l <= r) {
		int i = (l+r)/2;   //0 --> i-1
		int j = halflen - i;   // 0 --> j-1

		if(i < r and a[i] < b[j-1]) {
			i = i+1;
		}
		else if(i > 0 and a[i-1] > b[j]) {
			r = i-1;
		}
		else {
			// all the elements of b are smaller than any element of a
			int zmid = 0;
			if(i == 0) {
				zmid = b[j-1];
			}
			else if(j == 0) {
				zmid = a[i-1];
			}
			else {
				zmid = max(a[i-1], b[j-1]);
			}

			int zmid1 = 0;
			if(i == m ) {
				zmid1 = b[j];
			}
			else if(j == m) {
				zmid1 = a[i];
			}
			else {
				zmid1 = min(a[i], b[j]);
			}

			if((i+j)%2 == 0) {
				median = (zmid + float(zmid1)) /2;
			}
			else {
				median = zmid;
			}
			l = r+1;
		}
	}
	return median;
}


int main() {

	#ifndef ONLINE_JUDGEs
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int m ,n;
	cin>>m>>n;
	int a[m] , b[n];

	for(int i=0;i<m;i++) {
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++) {
		cin>>b[i];
	}

	cout<<median(a, b, m ,n)<<endl;

	return 0;
}

// or
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) {
            return  findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int low = 0, high = n1;
        
        while(low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 and left2 <= right1) {
                
                if((n1+n2) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else {
                    return max(left1, left2);
                }
            }
            
            else if(left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        
        return 0.0;
    }






    