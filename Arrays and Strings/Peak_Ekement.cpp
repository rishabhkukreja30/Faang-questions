#include<bits/stdc++.h>
using namespace std;

    int search(vector <int >&nums, int s, int e) {
        
        int mid = s + (e-s)/2;
        
        if((mid == 0 or nums[mid-1] <= nums[mid]) and (mid == nums.size()-1 or nums[mid] >= nums[mid+1])) {
            return mid;
        }
        
        else if(mid > 0 and nums[mid-1] > nums[mid]) {
            return search(nums, s ,mid-1);
        }
        else {
            return search(nums, mid+1, e);
        }
    }
    
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        
        return search(nums, s, e);
    }

