#include<bits/stdc++.h>
using namespace std;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == n) {
            return nums;
        }
        
        unordered_map <int, int> m;
        
        for(int i=0;i<n;i++) {
            m[nums[i]]++;
        }
        
        priority_queue <int, vector <int> , greater <int> > q[n+1];
        
        for(auto val : m) {
            int occ = val.second;
            int value = val.first;
            q[occ].push(value);
        }
        
        vector <int> ans;
        
        for(int i=n;i>=1;i--) {
            
            while(!q[i].empty() and k>0) {
                ans.push_back(q[i].top());
                q[i].pop();
                k--;
            }
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
	vector <int> nums;

	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}

	int k;
	cin>>k;

	vector <int> ans = kMostFrequentElements(nums, k);

	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<" ";
	}

	return 0;
}