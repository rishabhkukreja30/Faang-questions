
int max_sum = INT_MIN;

int maxPathSum(node* root) {

	//base case
	if(root == NULL) {
		return INT_MIN;
	}

	//recursive case
	int left_sum = maxPathSum(root->left);
	int right_sum = maxPathSum(root->right);

	int ans = root->data;
	if(left_sum > 0) {
		ans += left_sum;
	}
	if(right_sum > 0) {
		ans += right_sum;
	}

	max_sum = max(max_sum, ans);

	return root->data + max(0, max(left_sum, right_sum));
}