
void findPath(node* root, int curr_sum, int sum, vector <int> curr_path, vector <vector <int>> &paths) {
	if(root == NULL) {
		return;
	}
	curr_sum += root->data;
	curr_path.push_back(root->data);

	if(root->left == NULL and root->right == NULL) {
		if(curr_sum == sum ){
			paths.push_back(curr_path);
		}
	}
	findPath(root->left, curr_sum, sum, curr_path, paths);
	findPath(root->right, curr_sum, sum, curr_path, paths);
}


vector <vector <int> > pathSum(node* root, int sum) {
	vector <vector <int> > paths;
	vector <int> curr_path;
	if(root == NULL) {
		return paths;
	}

	findPath(root, 0, sum, curr_path, paths);
	return paths;
}