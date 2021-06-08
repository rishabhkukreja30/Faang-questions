

int kthLargest(vector <int >&nums, int k) {

	priority_queue <int, vector <int> , greater <int> > q;
	int count = 0;
	for(int i=0;i<nums.size();i++) {

		if(count < k) {
			q.push(nums[i]);
			count++;
		}
		else {
			if(nums[i] > q.top()) {
				q.pop();
				q.push(nums[i]);
			}
		}
	}
	return q.top();
}