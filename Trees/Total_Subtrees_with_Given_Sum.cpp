
int Sum(node* root) {
	if(root == NULL) {
		return 0;
	}

	int left_sum = Sum(root->left);
	int right_sum = Sum(root->right);

	return root->data + left_sum + right_sum;
}


int countSubtrees(node* root, int x) {
	if(root == NULL) {
		return 0;
	}
	int ans = 0;
	if(Sum(root) == x) {
		ans = 1;
	}

	int left_subtrees = countSubtrees(root->left, x);
	int right_subtrees = countSubtrees(root->right, x);

	return ans + left_subtrees + right_subtrees;
}