
bool pathSum(node* root ,int sum, int current_sum) {
	if(root == NULL) {
		return false;
	}

	if(root->left == NULL and root->right == NULL) {
		if(current_sum + root->data == sum) {
			return true;
		}
		else {
			return false;
		}
	}

	return pathSum(root->left, sum, current_sum + root->data) || pathSum(root->right, sum, current_sum  +root->data);
}